#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n;
int answer = 0;
vector<bool> check(n+1, false);
void dfs(int num, vector<vector<bool>> arr){
    for(int i=1; i<n+1; i++){
        if(arr[num][i] && !check[i]){
            check[i] = true;
            answer++;
            dfs(i, arr);
        }
    }
}
int main(){
    cin >> n;
    vector<vector<bool>> arr(n+1, vector<bool>(n+1,false));
    
    int num;
    cin >> num;
    for(int i=0; i<num; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }
    check[1] = true;
    dfs(1, arr);
    printf("%d\n", answer);
    return 0;
}
