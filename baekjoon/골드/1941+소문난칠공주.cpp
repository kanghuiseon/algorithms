#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<string> arr;
int people[26];
int visit[26][26];
vector<string> v;
int tmp[5][5];
int answer = 0;
// 7명의 학생
// 이다솜 파 4명 이상 있어야 함
// 칠공주 결성할 수 있는 경우의 수
// s : 이다솜, y : 임도연
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
// true면 다솜, false면 도연
bool isConnected(){
    memset(visit, 0, sizeof(visit));
    memset(tmp, 0, sizeof(tmp));
    int x, y;
    for(int i=0; i<25; i++){
        if(people[i] == 0){
            continue;
        }
        x = i/5;
        y = i%5;
        tmp[x][y] = 1;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = 1;
    int cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >=5 || visit[nx][ny] == 1){
                continue;
            }
            if(tmp[nx][ny] == 1){
                cnt++;
                q.push(make_pair(nx, ny));
                visit[nx][ny] = 1;
            }
        }
    }
    if(cnt==7){
        return true;
    }
    return false;
}
bool index(int num){
    int x = num/5;
    int y = num%5;
    if(arr[x][y] == 'S'){
        return true;
    }else{
        return false;
    }
}

void dfs(int idx, int s, int y){
    if(s+y == 7){
        if(s >= 4){
            if(isConnected()){
                answer++;
            }
        }
        return;
    }
    
    for(int i=idx; i<25; i++){
        if(people[i] == 1)
            continue;
        people[i] = 1;
        bool isDasom = index(i);
        if(isDasom){
            dfs(i, s+1, y);
        }else{
            dfs(i, s, y+1);
        }
        people[i] = 0;
    }
}
int main() {
    for(int i=0; i<5; i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }
    dfs(0, 0, 0);
    printf("%d\n", answer);
    return 0;
}
