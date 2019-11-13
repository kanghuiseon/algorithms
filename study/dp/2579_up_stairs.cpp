#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int stairs[303];
int dp[303];
int main(){
  int n,j;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d",&stairs[i]);
  dp[0] = stairs[0];
  dp[1] = max(stairs[0]+stairs[1],stairs[1]);
  dp[2] = max(stairs[0]+stairs[2],stairs[1]+stairs[2]);
  for(j=3; j<n; j++){
    dp[j] = max(stairs[j]+stairs[j-1]+dp[j-3],stairs[j]+dp[j-2]);
  }
  printf("%d\n",dp[j-1]);
  return 0;
}
