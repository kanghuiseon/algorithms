#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n,s,m;
    cin >> n >> s >> m;
    int Max = -1;
    vector<vector<bool>> dp(n+1, vector<bool>(1001, false));
    vector<int> arr(101,0);
    for(int i=1; i<n+1; i++){
        cin >> arr[i];
    }
    dp[0][s] = true;
    for(int i=1; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(!dp[i-1][j])
                continue;
            if(j-arr[i] >= 0)
                dp[i][j-arr[i]] = true;
            if(j+arr[i] <= m)
                dp[i][j+arr[i]] = true;
        }
    }
    for(int i=m; i>=0; i--){
        if(dp[n][i] == true){
            Max = i;
            break;
        }
        
    }
    printf("%d\n", Max);
    return 0;
}

