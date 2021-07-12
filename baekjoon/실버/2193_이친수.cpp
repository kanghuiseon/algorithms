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
    vector<long long int> dp(n+1);
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<n+1; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    printf("%lld\n", dp[n]);
    return 0;
}
