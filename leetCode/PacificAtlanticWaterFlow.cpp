class Solution {
public:
    // 왼, 오, 위, 아래
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n, m;
    // 현재 바다와 맞닿은곳에서 갈 수 있는 곳을 돈다.
    // 만약에 거기서 갈 수 있으면 바다 갈 수 있다는 얘기
    // 그래서 현재 위치에서 작은곳만 가는게 아니라 큰곳을 가야함
    vector<vector<bool>> pacific, atlantic;
    void dfs(vector<vector<int>>&arr, vector<vector<bool>>&ocean, int x, int y){
        ocean[x][y] = true;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !ocean[nx][ny] && arr[nx][ny] >= arr[x][y]){
                dfs(arr, ocean, nx, ny);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer;
        n = heights.size();
        m = heights[0].size();
        pacific = vector<vector<bool>>(n, vector<bool>(m, false));
        atlantic = vector<vector<bool>>(n, vector<bool>(m, false));

        if(n==0 || m==0)
            return answer;

        // left, right
        for(int i=0; i<n; i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m-1);
        }
        // up, down
        for(int i=0; i<m; i++){
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, n-1, i);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j]== 1 && atlantic[i][j] == 1){
                    answer.push_back({i, j});
                }
            }
        }
        return answer;
    }

};
