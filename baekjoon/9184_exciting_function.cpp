#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 101
using namespace std;

int dp[MAX][MAX][MAX];
int w(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0){
        return 1;
    }
    
    if(a > 20 || b > 20 || c > 20){
        if(dp[a][b][c] != 0)
            return dp[a][b][c];
        return dp[a][b][c] = w(20, 20, 20);
    }
    if(a<b && b<c){
        if(dp[a][b][c] != 0)
            return dp[a][b][c];
        return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else{
        if(dp[a][b][c] != 0)
            return dp[a][b][c];
        return dp[a][b][c] = w(a-1, b ,c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
}
int main(){
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    std::ios_base::sync_with_stdio(false);
    while(1){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1)
            break;
        int num = w(a, b, c);
        printf("w(%d, %d, %d) = %d\n", a, b, c, num);
    }
    return 0;
}
