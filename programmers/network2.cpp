#include <string>
#include <vector>
#define MAX 201
using namespace std;
vector<vector<int>> com;
bool check[MAX][MAX];
int answer = 0;
int num;
void dfs(int current){
    for(int i=0; i<num; i++){
        if(!check[current][i] && com[current][i]==1){
            check[current][i] = true;
            check[i][current] = true;
            dfs(i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    com = computers;
    num = n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j] && com[i][j] == 1){
                dfs(i);
                answer++;
            }
        }
    }
        return answer;
}
