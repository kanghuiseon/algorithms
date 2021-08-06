#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_INDEX 104
using namespace std;
int n, m;
vector<string> arr;
int check[MAX_INDEX][MAX_INDEX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(){
    scanf("%d %d", &m, &n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }
    check[0][0] = 1;
    pq.push(make_pair(0, make_pair(0, 0)));
    while(!pq.empty()){
        int cnt = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        if(x == n-1 && y == m-1){
            printf("%d\n", cnt);
            return 0;
        }
        pq.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny]){
                continue;
            }
            
            check[nx][ny] = 1;
            if(arr[nx][ny] == '1'){
                pq.push(make_pair(cnt+1, make_pair(nx, ny)));
                arr[nx][ny] = 0;
            }
            else if(arr[nx][ny] == '0'){
                pq.push(make_pair(cnt, make_pair(nx, ny)));
            }
        }
    }
    return 0;
}
