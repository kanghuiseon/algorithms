#include <iostream>
int dp[1003];
int main(){
  int N;
  scanf("%d", &N);
  dp[0]=1, dp[1]=2;
  for(int i=2; i<N; i++){
    dp[i] = dp[i-1] + dp[i-2];
    dp[i] = dp[i]%10007;
  }
  printf("%d\n",dp[N-1]);
  return 0;
}
