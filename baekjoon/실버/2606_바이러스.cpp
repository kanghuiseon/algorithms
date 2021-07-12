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
int arr[100][100];
int check[101];
int cnt=0;
void dfs(int n, int current){
    for(int i=1; i<n+1; i++){
        if(check[i] == 0 && arr[current][i] == 1){
            check[i] = 1;
            cnt++;
            dfs(n, i);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n, m;
    scanf("%d", &n);
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            arr[i][j] = 0;
            arr[j][i] = 0;
        }
    }
    for(int i=0; i<101; i++){
        check[i] = 0;
    }
    check[1] = 1;
    scanf("%d", &m);
    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    dfs(n, 1);
    printf("%d\n", cnt);
    return 0;
}

