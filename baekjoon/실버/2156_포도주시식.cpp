#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;
int dp[MAX];
int arr[MAX];
int main(){
    int n;
    cin >> n;
    for(int i=1; i<n+1; i++){
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = max(arr[2], arr[1]+arr[2]);
    for(int i=3; i<n+1; i++){
        int Max1 = -1;
        for(int j=0; j<=i-3; j++){
            Max1 = max(Max1, dp[j]);
        }
        int Max2 = -1;
        for(int j=0; j<=i-2; j++){
            Max2 = max(Max2, dp[j]);
        }
        dp[i] = max(arr[i]+arr[i-1]+Max1, arr[i]+Max2);
    }
    int Max = -1;
    for(int i=1; i<n+1; i++){
        Max = max(dp[i], Max);
    }
    printf("%d\n", Max);
    return 0;
}
