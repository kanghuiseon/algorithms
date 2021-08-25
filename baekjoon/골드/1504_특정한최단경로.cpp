#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#define MAX_INDEX 802
#define MAX 1000000
#define tt pair<int, int>
using namespace std;
int n, e;
int v1, v2;
vector<vector<pair<int, int>>> arr(MAX_INDEX);
vector<int> dp(MAX_INDEX, MAX);
void dijkstra(int start){
    for(int i=1; i<=n; i++){
        dp[i] = MAX;
    }
    priority_queue<tt, vector<tt>, greater<tt>> pq;
    pq.push(make_pair(0, start));
    dp[start] = 0;
    while(!pq.empty()){
        int distance = get<0>(pq.top());
        int node = get<1>(pq.top());
        pq.pop();
        for(int i=0; i<arr[node].size(); i++){
            int nextNode = arr[node][i].first;
            int nextDistance = arr[node][i].second;
            if(dp[nextNode] > distance + nextDistance){
                dp[nextNode] = distance + nextDistance;
                pq.push(make_pair(distance + nextDistance, nextNode));
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &e);
    for(int i=0; i<e; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr[a].push_back(make_pair(b, c));
        arr[b].push_back(make_pair(a, c));
    }
    scanf("%d %d", &v1, &v2);
    dijkstra(1);
    int oneToV1 = dp[v1];
    int oneToV2 = dp[v2];

    dijkstra(v1);
    int v1ToV2 = dp[v2];
    int v1ToN = dp[n];

    dijkstra(v2);
    int v2ToN = dp[n];

    int Min = MAX;
    Min = min(Min, oneToV1 + v1ToV2 + v2ToN);
    Min = min(Min, oneToV2 + v1ToV2 + v1ToN);
    if(Min == MAX || v1ToV2 == MAX)
        printf("-1\n");
    else{
        printf("%d\n", Min);
    }
    return 0;
}
