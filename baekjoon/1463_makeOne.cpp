#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>
#define MAX 1000001
using namespace std;
int dp[MAX];
int main(){
    int n;
    cin >> n;
    for(int i=1; i<n+1; i++){
        dp[i] = MAX;
    }
    dp[n] = 0;
    for(int i=n; i>=0; i--){
        if(i % 3 == 0){
            dp[i/3] = min(dp[i] + 1, dp[i/3]);
        
        }
        if(i % 2 == 0){
            dp[i/2] = min(dp[i] + 1, dp[i/2]);
        }
        dp[i-1] = min(dp[i] + 1, dp[i-1]);
    }
    printf("%d\n", dp[1]);
    return 0;
}
