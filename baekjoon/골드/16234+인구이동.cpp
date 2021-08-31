#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX_INDEX 52
using namespace std;
int n, l, r;
int arr[MAX_INDEX][MAX_INDEX];
// 왼 오 위 아래
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visit[MAX_INDEX][MAX_INDEX];
int cc[MAX_INDEX][MAX_INDEX];
int tmp[MAX_INDEX][MAX_INDEX];
// 한 영역의 갯수와 합 구하기
void bfs2(int x, int y){
    int cnt = 1; int sum = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int check[MAX_INDEX][MAX_INDEX];
    visit[x][y] = 1;
    sum += arr[x][y];
    memset(check, 0, sizeof(check));
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        check[cx][cy] = 1;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n){
                continue;
            }
            if(abs(arr[nx][ny] - arr[cx][cy]) >= l && abs(arr[nx][ny] - arr[cx][cy]) <= r){
                if(check[nx][ny])
                    continue;
                check[nx][ny] = 1;
                visit[nx][ny] = 1;
                cnt++;
                sum += arr[nx][ny];
                q.push(make_pair(nx, ny));
            }
        }
    }
    // 한 영역에 sum/cnt값으로 채우기
    int num = sum / cnt;
    q.push(make_pair(x, y));
    memset(check, 0, sizeof(check));
    check[x][y] = 1;
    tmp[x][y] = num;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        check[cx][cy] = 1;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n){
                continue;
            }
            if(abs(arr[nx][ny] - arr[cx][cy]) >= l && abs(arr[nx][ny] - arr[cx][cy]) <= r){
                if(check[nx][ny])
                    continue;
                check[nx][ny] = 1;
                tmp[nx][ny] = num;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
// 벽 갯수 구하기
void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int check[MAX_INDEX][MAX_INDEX];
    visit[x][y] = 1;
    memset(check, 0, sizeof(check));
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        check[cx][cy] = 1;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n || abs(arr[nx][ny] - arr[cx][cy]) < l || abs(arr[nx][ny] - arr[cx][cy]) > r){
                continue;
            }
            if(abs(arr[nx][ny] - arr[cx][cy]) >= l && abs(arr[nx][ny] - arr[cx][cy]) <= r){
                cc[cx][cy] -= 1;
            }
            if(check[nx][ny])
                continue;
            check[nx][ny] = 1;
            visit[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
}
// 초기화
void setting(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            visit[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            tmp[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cc[i][j] = 4;
        }
    }
}


int main(){
    scanf("%d %d %d", &n, &l, &r);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int answer = 0;
    setting();
    while(true){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!visit[i][j]){
                    bfs(i, j);
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                visit[i][j] = 0;
            }
        }
        // 만약 더 이상 깨질 장벽이 없다면 break;
        int cnt2=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(cc[i][j] == 4){
                    cnt2++;
                }
            }
        }
        if(cnt2 == n*n)
            break;
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(cc[i][j] != 4 && !visit[i][j]){
                    bfs2(i, j);
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(tmp[i][j] != 0)
                    arr[i][j] = tmp[i][j];
            }
        }
        setting();
        answer++;
    }
    printf("%d\n", answer);
    return 0;
}
