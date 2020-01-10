#include <iostream>
using namespace std;
int dp[1003][3];
int color[1003][3];
int main(){
  int N;
  scanf("%d",&N);
  for(int i=1; i<=N; i++){
    scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);
  }

  for(int k=0; k<=N; k++){
    dp[k][0] = min(dp[k-1][1],dp[k-1][2])+color[k][0];
    dp[k][1] = min(dp[k-1][0],dp[k-1][2])+color[k][1];
    dp[k][2] = min(dp[k-1][0],dp[k-1][1])+color[k][2];
  }
  printf("%d\n",min(min(dp[N][0],dp[N][1]),dp[N][2]));
  return 0;
}
