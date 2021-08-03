#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 10
using namespace std;
int n, m;
int arr[MAX_INDEX][MAX_INDEX];
vector<pair<int, pair<int, int>>> cctv;
int cctvNum=0;
int Min = 0x7fffffff;
void fill_cctv(int x, int y, int dir){
    // 0, 1, 2, 3: 차례대로 동, 서, 남, 북
    switch (dir) {
        case 0:
            for(int i=y+1; i<m; i++){
                if(arr[x][i] == 6){
                    break;
                }
                else if(arr[x][i] == 0){
                    arr[x][i] = -1;
                }
            }
            break;
        case 1:
            for(int i=y-1; i>=0; i--){
                if(arr[x][i] == 6){
                    break;
                }
                else if(arr[x][i] == 0){
                    arr[x][i] = -1;
                }
            }
            break;
        case 2:
            for(int i = x+1; i<n; i++){
                if(arr[i][y] == 6){
                    break;
                }
                else if(arr[i][y] == 0){
                    arr[i][y] = -1;
                }
            }
            break;
        case 3:
            for(int i = x-1; i>=0; i--){
                if(arr[i][y] == 6){
                    break;
                }
                else if(arr[i][y] == 0){
                    arr[i][y] = -1;
                }
            }
            break;
        default:
            break;
    }
}
void dfs(int cnt){
    //모든 경우를 다 보면
    if(cnt == cctvNum){
        int tmp=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 0)
                    tmp++;
            }
        }
        Min = min(Min, tmp);
        return;
    }
    
    int tmp[MAX_INDEX][MAX_INDEX];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[i][j] = arr[i][j];
        }
    }
    int num = cctv[cnt].first, x = cctv[cnt].second.first, y = cctv[cnt].second.second;
    switch (num) {
        case 1:
            for(int i=0; i<4; i++){
                fill_cctv(x, y, i);
                dfs(cnt+1);
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        arr[i][j] = tmp[i][j];
                    }
                }
            }
            break;
        case 2:
            fill_cctv(x, y, 0);
            fill_cctv(x, y, 1);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            
            fill_cctv(x, y, 2);
            fill_cctv(x, y, 3);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            break;
        case 3:
            fill_cctv(x, y, 0);
            fill_cctv(x, y, 3);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            fill_cctv(x, y, 0);
            fill_cctv(x, y, 2);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            fill_cctv(x, y, 1);
            fill_cctv(x, y, 2);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            fill_cctv(x, y, 1);
            fill_cctv(x, y, 3);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            break;
        case 4:
            fill_cctv(x, y, 0);
            fill_cctv(x, y, 1);
            fill_cctv(x, y, 3);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            fill_cctv(x, y, 0);
            fill_cctv(x, y, 2);
            fill_cctv(x, y, 3);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            fill_cctv(x, y, 0);
            fill_cctv(x, y, 1);
            fill_cctv(x, y, 2);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            fill_cctv(x, y, 1);
            fill_cctv(x, y, 2);
            fill_cctv(x, y, 3);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            break;
        case 5:
            fill_cctv(x, y, 1);
            fill_cctv(x, y, 2);
            fill_cctv(x, y, 3);
            fill_cctv(x, y, 0);
            dfs(cnt+1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[i][j] = tmp[i][j];
                }
            }
            break;
        default:
            break;
    }
}


int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            scanf("%d", &a);
            arr[i][j] = a;
            if(a>=1 && a<=5){
                cctv.push_back(make_pair(a, make_pair(i, j)));
                cctvNum++;
            }
        }
    }
    dfs(0);
    printf("%d\n", Min);
    return 0;
}
