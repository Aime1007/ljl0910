//
//  main.cpp
//  AVLTree
//
//  Created by s20181106275 on 2019/12/10.
//  Copyright © 2019 s20181106275. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct AVLNode *AVLTree;
struct AVLNode {
    int data;
    AVLTree left;
    AVLTree right;
    int height;
};
int max(int a, int b)
{
    if(a>b) return a;
    else return b;
}

AVLTree Insert(AVLTree T, int x)
{
    if(!T) {
        T=new AVLNode;
        T->data=x;
        T->height=1;
        T->left=T->right=NULL;
    }
    else if(x<T->data) {
        T->left=Insert(T->left, x);
        if(T->left->height-T->right->height==2) {
            
        }
    }
    else if(x>T->data) {
        T->right=Insert(T->right, x);
    }
    return T;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
