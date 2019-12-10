//
//  main.cpp
//  1016
//
//  Created by s20181106275 on 2019/11/19.
//  Copyright © 2019 s20181106275. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int visited[30], a[30], n;
int prime(int x) {
    for (int i = 2; i <= x/2; i++)
        if (x % i == 0) return 0;
    return 1;
}
void dfs(int step) {
    if (step == n+1 && prime(a[1]+a[n])) {
        for (int i = 1; i <= n-1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (visited[i] == 0) {
            if (prime(i+a[step-1])) {
                visited[i] = 1;
                a[step] = i;
                dfs(step+1);
                visited[i] = 0;
            }
        }
    }
    return;
}
int main() {
    int flag = 0;
    a[1] = 1;
    while (~scanf("%d", &n)) {
        memset(visited, 0, sizeof(visited));
        flag ++;
        printf("Case %d:\n", flag);
        dfs(2);
        printf("\n");
    }
    return 0;
}
