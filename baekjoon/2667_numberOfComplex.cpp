#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;
bool check[26][26];
int arr[26][26];
int cnt=1;
void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
            if(!check[nx][ny] && arr[nx][ny] == 1){
                check[nx][ny] = true;
                cnt++;
                dfs(nx, ny);
            }
        }
    }
}
int main(){
    cin >> n;
    string num;
    vector<int> results;
    for(int i=0; i<n; i++){
        cin >> num;
        for(int j=0; j<n; j++){
            arr[i][j] = num[j] - '0';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && !check[i][j]){
                check[i][j] = true;
                 dfs(i, j);
                results.push_back(cnt);
                cnt=1;
            }
        }
    }
    sort(results.begin(), results.end());
    printf("%d\n", results.size());
    for(int i=0; i<results.size(); i++){
        printf("%d\n", results[i]);
    }
    return 0;
}
