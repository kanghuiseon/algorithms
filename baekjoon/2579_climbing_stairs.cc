#include <iostream>
using namespace std;
int dp[303];
int main(){
  int stairs[303]={0,};
  int N;
  scanf("%d",&N);
  for(int i=0; i<N; i++)
    scanf("%d",&stairs[i]);
  dp[0] = stairs[0];
  dp[1] = max(stairs[0]+stairs[1],stairs[1]);
  dp[2] = max(stairs[0]+stairs[2], stairs[1]+stairs[2]);
  for(int j=3; j<N; j++)
    dp[j] = max(stairs[j]+stairs[j-1]+dp[j-3],stairs[j]+dp[j-2]);
  printf("%d\n",dp[N-1]);
  return 0;
}
