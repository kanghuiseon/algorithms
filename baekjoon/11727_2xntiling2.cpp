#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>
#define MAX 1001
using namespace std;
int dp[MAX];
int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<n+1; i++){
        dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
    }
    printf("%d\n", dp[n]);
    return 0;
}
