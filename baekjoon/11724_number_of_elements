//
//  main.cpp
//  study
//
//  Created by 강희선 on 2021/02/26.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
int arr[1002][1002];
int check[1002];
void dfs(int n, int current){
    for(int i=1; i<n+1; i++){
        if(check[i] == 0 && arr[current][i] == 1){
            check[i] = 1;
            dfs(n, i);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n==1){
        printf("%d\n", 1);
        return 0;
    }
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            arr[i][j] = 0;
        }
    }
    for(int i=0; i<n+1; i++){
        check[i] = 0;
    }
    int a, b;
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    int cnt = 0;
    for(int i=1; i<n+1; i++){
        if(check[i]==0){
            dfs(n,i);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

