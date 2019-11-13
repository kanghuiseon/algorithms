#include <iostream>
#include <stdio.h>
int main(){
  int test,num;
  int dp[43]={0,};
  scanf("%d",&test);
  dp[0]=0; dp[1]=1;
  while(test--){
    scanf("%d",&num);
    if(num == 0)
      printf("1 0\n");
    else if(num==1)
      printf("0 1\n");
    else{
      for(int i=2; i<=num; i++){
        dp[i]=dp[i-1]+dp[i-2];
      }
      printf("%d %d\n", dp[num-1],dp[num]);
    }
  }
  return 0;
}
