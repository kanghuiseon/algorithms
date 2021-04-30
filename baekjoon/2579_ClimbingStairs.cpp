#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>
#define MAX 100001
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1, 0);
    vector<int> dp(n+1, 0);
    for(int i=1; i<n+1; i++){
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = max(dp[0] + arr[2], dp[1]+arr[2]);
    for(int i=3; i<n+1; i++){
        dp[i] = max(arr[i]+arr[i-1]+dp[i-3], arr[i] + dp[i-2]);
    }
    printf("%d\n", dp[n]);
    return 0;
}
