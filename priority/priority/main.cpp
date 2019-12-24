//
//  main.cpp
//  priority
//
//  Created by s20181106275 on 2019/12/17.
//  Copyright © 2019 s20181106275. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;


int main(int argc, const char * argv[]) {
    priority_queue<int, vector<int>, greater<int> > pque;
    
    pque.push(3);
    pque.push(5);
    pque.push(1);
    
    while (!pque.empty()) {
        cout << pque.top() <<endl;
        pque.pop();
    }
}
