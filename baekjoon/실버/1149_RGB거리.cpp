#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1002][4];
int arr[1002][4];
int main(){
    int n;
    cin >> n;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<4; j++){
            cin >> arr[i][j];
            if(i==1){
                dp[i][j] = arr[i][j];
            }
        }
    }
    for(int i=2; i<n+1; i++){
        for(int j=1; j<4; j++){
            if(j==1)
                dp[i][j] = min(dp[i-1][j+1]+arr[i][j], dp[i-1][j+2]+arr[i][j]);
            else if(j==2)
                dp[i][j] = min(dp[i-1][j-1]+arr[i][j], dp[i-1][j+1]+arr[i][j]);
            else if(j==3)
                dp[i][j] = min(dp[i-1][j-2]+arr[i][j], dp[i-1][j-1]+arr[i][j]);
        }
    }
    int Min=1000003;
    for(int i=1; i<4; i++)
        Min = min(Min, dp[n][i]);
    printf("%d\n", Min);
    return 0;
}
