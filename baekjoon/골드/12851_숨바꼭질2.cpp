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
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int cnt = 0;
int t = 0;
bool visit[100001];
void bfs(int n, int k){
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    visit[n] = true;
    while(!q.empty()){
        int current = q.front().first;
        int time = q.front().second;
        q.pop();
        visit[current] = true;
        if(cnt && t==time && current==k)
            cnt++;
        if(!cnt && current == k){
            cnt++;
            t = time;
        }
        if(current-1 >= 0 && !visit[current-1]){
            q.push(make_pair(current-1, time+1));
        }
        if(current+1 < 100001 && !visit[current+1]){
            q.push(make_pair(current+1, time+1));
        }
        if(current*2 < 100001 && !visit[current*2]){
            q.push(make_pair(current*2, time+1));
        }
    }
}
int main(int argc, const char * argv[]) {
    int n, k;
    scanf("%d %d", &n, &k);
    bfs(n, k);
    cout << t << endl << cnt << endl;
    return 0;
}

