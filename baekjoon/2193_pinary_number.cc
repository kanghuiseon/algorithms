#include <iostream>
using namespace std;
long long int dp[100];
int main(){
  int N;
  scanf("%d",&N);
  dp[0] = 1, dp[1] = 1;
  for(int i=2; i<N; i++)
    dp[i] = dp[i-1] + dp[i-2];
  printf("%lld\n",dp[N-1]);
  return 0;
}
