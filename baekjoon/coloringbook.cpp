#include <iostream>
#include <vector>
using namespace std;
//[[1, 1, 1, 0],
//[1, 2, 2, 0],
//[1, 0, 0, 1],
//[0, 0, 0, 1],
//[0, 0, 0, 3],
//[0, 0, 0, 3]]
int cnt;
int dfs(int m, int n, int x, int y, vector<vector<int>> picture, int num, int dx[4], int dy[4], bool check[101][101]){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>-1 && nx<m && ny>-1 && ny<n){
            if(!check[nx][ny] && picture[nx][ny] != 0 && picture[nx][ny] == num){
                check[nx][ny] = true;
                cnt++;
                dfs(m, n, nx, ny, picture, num, dx, dy, check);
            }
        }
    }
    return cnt;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    int number_of_area = 0;
    int max_size_of_one_area = -1;
    bool check[101][101] = {false,};
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    cnt=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j] && picture[i][j] != 0){
                int ans = dfs(m, n, i, j, picture, picture[i][j], dx, dy, check);
                number_of_area++;
                cnt=0;
                max_size_of_one_area = max(max_size_of_one_area, ans);
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main() {
    vector<int> ans = solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
    for(int i=0; i<2; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}

