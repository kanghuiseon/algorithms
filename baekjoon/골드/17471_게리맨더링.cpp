#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#define MAX_INDEX 11
#define MAX 0x7fffffff
using namespace std;
int n;
int nums[MAX_INDEX];
int Min = MAX;
vector<vector<int>> v(MAX_INDEX);
int visit[MAX_INDEX];
bool bfs(vector<int> a, bool flag){
    queue<int> q;
    int check[MAX_INDEX] = {0,};
    q.push(a[0]);
    check[a[0]] = 1;
    int cnt = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<v[node].size(); i++){
            if(check[v[node][i]] || visit[v[node][i]] != flag){
                continue;
            }
            q.push(v[node][i]);
            check[v[node][i]] = 1;
            cnt++;
        }
    }
    if(cnt == a.size()){
        return true;
    }
    return false;
}
bool canMake(){
    vector<int> a;
    vector<int> b;
    for(int i=1; i<=n; i++){
        if(visit[i])
            a.push_back(i);
        else
            b.push_back(i);
    }
    
    if(a.empty() || b.empty())
        return false;
    if(!bfs(a, true)){
        return false;
    }
    if(!bfs(b, false)){
        return false;
    }
    return true;
}
void dfs(int start, int cnt){
    if(cnt >= 1){
        if(canMake()){
            int numA=0, numB=0;
            for(int i=1; i<=n; i++){
                if(visit[i]){
                    numA += nums[i];
                }else{
                    numB += nums[i];
                }
            }
            Min = min(Min, abs(numA-numB));
        }
    }
    for(int i=start; i<=n; i++){
        if(visit[i])
            continue;
        visit[i] = 1;
        dfs(i+1, cnt+1);
        visit[i] = 0;
    }
}
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &nums[i]);
    }
    int tmp = n;
    int index=1;
    while(tmp--){
        int k;
        cin >> k;
        while(k--){
            int a;
            cin >> a;
            v[index].push_back(a);
        }
        index++;
    }
    dfs(1, 0);
    if(Min == MAX)
        printf("-1\n");
    else{
        printf("%d\n", Min);
    }
    return 0;
}
