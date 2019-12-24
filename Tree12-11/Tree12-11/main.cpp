//
//  main.cpp
//  Tree12-11
//
//  Created by s20181106275 on 2019/12/11.
//  Copyright © 2019 s20181106275. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
typedef struct TNode *BinTree;
struct TNode {
    int data;
    TNode *left;
    TNode *right;
};

BinTree Insert(BinTree BST, int x)
{
    if(!BST) {
        BST=new TNode;
        BST->data=x;
        BST->left=BST->right=NULL;
    }
    else {
        if(x<BST->data) {
            BST->left=Insert(BST->left, x);
        }
        else {
            BST->right=Insert(BST->right, x);
        }
    }
    return BST;
}
BinTree Create()
{
    BinTree BT,T;
    int data;
    queue<BinTree> q;
    cin >> data;
    if(data ==0) return NULL;
    else {
        BT=new TNode;
        BT->data=data;
        BT->left=BT->right=NULL;
        q.push(BT);
    }
    
    while(!q.empty()) {
        T=q.front();
        q.pop();
        cin >> data;
        if(data ==0) T->left=NULL;
        else {
            T->left=new TNode;
            T->left->data=data;
            T->left->left=T->left->right=NULL;
            q.push(T->left);
        }
        
        cin >> data;
        if(data ==0) T->right=NULL;
        else {
            T->right=new TNode;
            T->right->data=data;
            T->right->left=T->right->right=NULL;
            q.push(T->right);
        }
    }
    return BT;
}
BinTree FindMin(BinTree BT)
{
    if(!BT) return NULL;
    else if(!BT->left) return BT;
    else return FindMin(BT->left);
}
BinTree Delete(BinTree BT,int x)
{
    BinTree T;
    if(!BT) cout<<"找不到该节点"<<endl;
    else if(x<BT->data)
        BT->left=Delete(BT->left, x);
    else if(x>BT->data)
        BT->right=Delete(BT->right, x);
    else {
        if(BT->left&&BT->right) {
            T=FindMin(BT->right);
            BT->data=T->data;
            BT->right=Delete(BT->right, BT->data);
        }
        else {
            T=BT;
            if(!BT->left) {
                BT=BT->right;
            }
            else {
                BT=BT->left;
            }
            free(T);
        }
    }
    return BT;
}
void PrintTree(BinTree BT, int n)
{
    if(!BT) return ;
    PrintTree(BT->right, n+1);
    for(int i=0; i<n; i++) {
        cout<<"   ";
    }
    cout<< BT->data<<endl;
    PrintTree(BT->left, n+1);
}
int main(int argc, const char * argv[]) {
    BinTree BST=NULL;
//    BT=Create();
    BST=Insert(BST, 25);
    BST=Insert(BST, 17);
    BST=Insert(BST, 31);
    BST=Insert(BST, 46);
    BST=Delete(BST, 31);
    BST=Delete(BST, 46);
    BST=Delete(BST, 25);
//    PrintTree(BT, 1);
    PrintTree(BST, 1);
    return 0;
}
