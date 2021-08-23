#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_INDEX 302
#define MAX 0x7fffffff
using namespace std;
int n, m, k;
int dp[MAX_INDEX][MAX_INDEX];
vector<vector<pair<int, int>>> v(MAX_INDEX);
int dfs(int cnt, int current){
    if(current == n){
        return 0;
    }
    if(cnt == m){
        return -MAX;
    }
    if(dp[current][cnt] != 0){
        return dp[current][cnt];
    }
    dp[current][cnt] = -MAX;
    for(int i=0; i<v[current].size(); i++){
        int next = v[current][i].first;
        int c = v[current][i].second;
        dp[current][cnt] = max(dp[current][cnt], dfs(cnt+1, next) + c);
    }
    return dp[current][cnt];
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<k; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a > b)
            continue;
        v[a].push_back(make_pair(b, c));
    }

    printf("%d\n", dfs(1, 1));
    return 0;
}
