#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 100000001
using namespace std;

int main(){
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<vector<pair<int, int>>> arr(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> prices(n+1, MAX);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr[a].push_back(make_pair(b, c));
    }
    int start, end;
    scanf("%d %d", &start, &end);
    prices[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int price = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        // 최소비용때문에
        if(prices[node] < price){
            continue;
        }
        for(int i=0; i<arr[node].size(); i++){
            if(price + arr[node][i].second < prices[arr[node][i].first]){
                prices[arr[node][i].first] = price + arr[node][i].second;
                pq.push(make_pair(price + arr[node][i].second, arr[node][i].first));
            }
        }
    }
    
    printf("%d\n", prices[end]);
    return 0;
}
