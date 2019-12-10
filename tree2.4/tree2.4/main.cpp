
#include <iostream>
using namespace std;

struct node {
    int val;
    node *lch, *rch;
};

node *insert (node *p, int x)
{
    if(p == NULL) {
        node *q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    }
    else {
        if(x < p->val) p->lch = insert(p->lch, x);
        else p->rch = insert(p->rch, x);
        return p;
    }
}
int main(int argc, const char * argv[]) {

    return 0;
}
