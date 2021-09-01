#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX_INDEX 204
#define MAX 30000000
using namespace std;
int arr[MAX_INDEX][MAX_INDEX];
int check[MAX_INDEX];
int Min = MAX;
void dfs(int start, int n, int a, int b, vector<int> v, int sum){
    if(start == a){
        Min = min(Min, arr[start][b] + sum);
    }
    else if(start == b){
        Min = min(Min, arr[start][a] + sum);
    }else{
        if(Min > arr[start][a] + arr[start][b] + sum){
            Min = arr[start][a] + arr[start][b] + sum;
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!check[i])
            cnt++;
    }
    if(cnt==0)
        return;
    
    
    int MM = MAX;
    int index=0;
    for(int i=1; i<=n; i++){
        if(start == i || arr[start][i] == MAX){
            continue;
        }
        int j;
        for(j=0; j<v.size(); j++){
            if(v[j] == i)
                break;
        }
        if(j == v.size()){
            if(MM > arr[start][i]){
                MM = arr[start][i];
                index = i;
            }
        }
    }
    v.push_back(index);
    check[index] = 1;
    dfs(index, n, a, b, v, sum+MM);
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = MAX;
        }
    }
    for(int i=0; i<fares.size(); i++){
        int a = fares[i][0], b = fares[i][1], f = fares[i][2];
        arr[a][b] = f;
        arr[b][a] = f;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    check[s] = 1;
    check[a] = 1; check[b] = 1;
    dfs(s, n, a, b, {s}, 0);
    answer = Min;
    return answer;
}

int main(){
    //solution(6, 4, 6, 2, {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}});
    //solution(6, 4, 5, 6, {{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}});
    int answer = solution(6, 4, 5, 6, {{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}});
    cout << answer << endl;
    return 0;
}
