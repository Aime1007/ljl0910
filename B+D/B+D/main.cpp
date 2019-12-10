//
//  main.cpp
//  B+D
//
//  Created by s20181106275 on 2019/11/19.
//  Copyright © 2019 s20181106275. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Node {
    int x,y;
};
int N,E;
int G[15][15];
int visited[15][15];
int m,n;
queue<Node>q;

int BFS()
{
    while(!q.empty()) {
        Node p = q.front();
        q.pop();
        
        for(int i=0; i<m; i++) {
            
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    cin >> N >> E;
    for(int i=0; i<E; i++ ) {
        cin >> m >> n;
        G[m][n] = 1;
    }
    while(!q.empty()) {
        q.pop();
    }
    Node p;
    p.x=p.y=0;
    q.push(p);
    int ans = BFS();
    return 0;
}
