//
//  main.cpp
//  DeleteBST
//
//  Created by s20181106275 on 2019/12/10.
//  Copyright © 2019 s20181106275. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct TNode *BinTree;
struct TNode {
    int data;
    BinTree left;
    BinTree right;
};

BinTree Insert(BinTree BT, int x)
{
    if(!BT) {
        BT=new TNode;
        BT->data=x;
        BT->left=BT->right=NULL;
    }
    else {
        if(x<BT->data) {
            BT->left=Insert(BT->left, x);
        }
        else if(x>BT->data) {
            BT->right=Insert(BT->right, x);
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
BinTree Delete(BinTree BT, int x)
{
    BinTree tmp;
    if(!BT) cout<<"没找到该节点"<<endl;
    else if(x<BT->data) {
        BT->left=Delete(BT->left, x);
    }
    else if(x>BT->data) {
        BT->right=Delete(BT->right, x);
    }
    else {
        if(BT->left&&BT->right) {
            tmp=FindMin(BT->right);
            BT->data=tmp->data;
            BT->right=Delete(BT->right, BT->data);
        }
        else {
            tmp=BT;
            if(!BT->left) {
                BT=BT->right;
            }
            else {
                BT=BT->left;
            }
            free(tmp);
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
    cout<< BT->data <<endl;
    PrintTree(BT->left, n+1);
}
int main(int argc, const char * argv[]) {
    BinTree BT=NULL;
    BT=Insert(BT, 5);
    PrintTree(BT,1);
    cout<<endl;
    BT=Insert(BT, 7);
    PrintTree(BT,1);
    cout<<endl;
    BT=Insert(BT, 3);
    PrintTree(BT,1);
    cout<<endl;
    Delete(BT, 3);
    PrintTree(BT,1);
    cout<<endl;
    return 0;
}
