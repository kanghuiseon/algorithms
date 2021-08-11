#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX_INDEX 10004
using namespace std;
int n, m;
int dp[MAX_INDEX];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        vector<int> coins;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            int a;
            scanf("%d", &a);
            coins.push_back(a);
        }
        int m;
        scanf("%d", &m);
        
        dp[0] = 1;
        for(int i=0; i<coins.size(); i++){
            for(int j=coins[i]; j<=m; j++){
                dp[j] = dp[j] + dp[j-coins[i]];
            }
        }
        printf("%d\n", dp[m]);
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}

