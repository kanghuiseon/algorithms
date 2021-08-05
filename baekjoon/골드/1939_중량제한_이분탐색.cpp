#include <iostream>
#include <vector>
#include <queue>
#define MAX_INDEX 100004
using namespace std;
int check[MAX_INDEX];
vector<vector<pair<int, int>>> arr(MAX_INDEX);
int n, m, s, e;
bool bfs(int weight){
    queue<int> q;
    q.push(s);
    check[s] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == e)
            return true;
        for(int i=0; i<arr[node].size(); i++){
            if(!check[arr[node][i].first] && weight <= arr[node][i].second){
                q.push(arr[node][i].first);
                check[arr[node][i].first] = 1;
            }
        }
    }
    return false;
}

int main(){
    int Max = -1;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d",&a, &b, &c);
        arr[a].push_back(make_pair(b, c));
        arr[b].push_back(make_pair(a, c));
        Max = max(Max, c);
    }
    scanf("%d %d", &s, &e);
    int left = 0, right = Max;
    while(left <= right){
        memset(check, 0, sizeof(check));
        int mid = (left+right)/2;
        if(bfs(mid)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    printf("%d\n", right);
    return 0;
}
