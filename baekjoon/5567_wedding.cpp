#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
bool arr[501][501] = {false,};
bool check[501] = {false,};
queue<pair<int, int>> q;
int n, m;
int cnt=0;
void bfs(){
    while(!q.empty()){
        int node = q.front().first;
        int relation = q.front().second;
        if(relation == 2)
            break;
        q.pop();
        for(int i=1; i<=n; i++){
            if(arr[node][i] == true && !check[i]){
                q.push(make_pair(i, relation+1));
                check[i] = true;
                cnt++;
            }
        }
    }
    
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }
    q.push(make_pair(1, 0));
    check[1] = true;
    bfs();
    printf("%d\n", cnt);
    return 0;
}

