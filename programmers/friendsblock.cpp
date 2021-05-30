#include <string>
#include <vector>

using namespace std;

bool check[31][31];
vector<string> b;

vector<string> down(int m, int n, vector<string> tmp){
    for(int i=m-1; i>-1; i--){
        for(int j=n-1; j>-1; j--){
            if(tmp[i][j] == '0'){
                continue;
            }
            else{
                for(int k=i+1; k<m; k++){
                    if(tmp[k][j] == '0'){
                        if(k==m-1){
                            tmp[k][j] = tmp[i][j];
                            tmp[i][j] = '0';
                            break;
                        }
                        continue;
                    }
                    else{
                        if(tmp[k-1][j] == '0'){
                            tmp[k-1][j] = tmp[i][j];
                            tmp[i][j] = '0';
                        }
                        else{
                            break;
                        }
                        
                        
                    }
                }
            }
        }
    }
    return tmp;
}
bool checkFour(int x, int y, char alpha, int m, int n){
    // 왼쪽 위
    if(x-1 > -1 && y-1 > -1){
        if(b[x-1][y-1] == alpha && b[x-1][y] == alpha && b[x][y-1] == alpha){
            return true;
        }
    }
    if(x-1 > -1 && y+1 < n){
        // 오른쪽 위
        if(b[x-1][y] == alpha && b[x-1][y+1] == alpha && b[x][y+1] == alpha){
            return true;
        }
    }
    if(y-1 > -1 && x+1 < m){
        // 왼쪽 아래
        if(b[x][y-1] == alpha && b[x+1][y-1] == alpha && b[x+1][y] == alpha){
            return true;
        }
    }
    if(y+1 < n && x+1 < m){
        // 오른쪽 아래
        if(b[x][y+1] == alpha && b[x+1][y] == alpha && b[x+1][y+1] == alpha){
            return true;
        }
    }
    return false;
}
// m : 높이, n : 폭
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    b = board;
    while(true){
        vector<string> tmp = b;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(b[i][j] != '0' && checkFour(i, j, b[i][j], m, n)){
                    check[i][j] = true;
                    tmp[i][j] = '0';
                    answer++;
                }
            }
        }
        bool flag = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(check[i][j] == true){
                    flag = true;
                }
            }
        }
        if(flag){
            vector<string> ans = down(m, n, tmp);
            b = ans;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    check[i][j] = false;
                }
            }
        }
        else{
            break;
        }
        
    }
    return answer;
}
