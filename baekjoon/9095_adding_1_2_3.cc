#include <iostream>
using namespace std;
int dp[12];
int main(){
  int n,num;
  scanf("%d",&n);
  dp[1]=1, dp[2]=2, dp[3]=4;
  while(n--){
    scanf("%d",&num);
    for(int i=4; i<=num; i++){
      dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    printf("%d\n",dp[num]);
  }
  return 0;
}
