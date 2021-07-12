#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX 10001
using namespace std;
int Max=-0x7fffffff, Min=0x7fffffff;
vector<int> arr(12);

int n;
// 1 2 3 4 5 6
// 2 1 1 1
void dfs(int index, int sum, vector<int>& op){
    if(index == n){
        Max = max(Max, sum);
        Min = min(Min, sum);
        return;
    }
    for(int i=0; i<4; i++){
        if(op[i] != 0){
            op[i]-=1;
            if(i==0){
                dfs(index+1, sum+arr[index], op);
                op[i] += 1;
            }
            else if(i==1){
                dfs(index+1, sum-arr[index], op);
                op[i] += 1;
            }
            else if(i==2){
                dfs(index+1, sum*arr[index], op);
                op[i] += 1;
            }
            else if(i==3){
                if(sum < 0){
                    int n = -sum;
                    dfs(index+1, -(n/arr[index]), op);
                }else{
                    dfs(index+1, sum/arr[index], op);
                }
                op[i] += 1;
            }
        }
    }
}
int main(){
    cin >> n;
    vector<int> op(4);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
    }
    dfs(1, arr[0], op);
    printf("%d\n%d\n", Max, Min);
    return 0;
}
