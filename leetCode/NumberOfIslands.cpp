class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n, m;
    int check[303][303]= {0,};
    vector<vector<char>> g;
    void dfs(int x, int y){
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || g[nx][ny] == '0'){
                continue;
            }
            check[nx][ny] = 1;
            dfs(nx, ny);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        g = grid;
        int answer = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && check[i][j] == 0){
                    check[i][j] = 1;
                    dfs(i, j);
                    answer++;
                }
            }
        }
        return answer;
    }
};
