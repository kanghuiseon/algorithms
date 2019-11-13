#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
  int num;
  int dp[3];
  dp[0]=1; dp[1]=2;
  scanf("%d",&num);
  for(int i=2; i<num; i++){
    dp[2] = (dp[0] + dp[1])%15746;
    dp[0] = dp[1];
    dp[1] = dp[2];
  }
  printf("%d\n",dp[2]);
  return 0;
}
