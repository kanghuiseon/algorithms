#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(1001, vector<int>(1001, 0));
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(a[i] == b[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    printf("%d\n", dp[a.size()][b.size()]);
    return 0;
}

