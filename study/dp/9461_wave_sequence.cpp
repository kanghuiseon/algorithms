#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  int test,i;
  unsigned long dp[101];
  dp[0]=0; dp[1]=1; dp[2]=1; dp[3]=1; dp[4]=2;
  scanf("%d",&test);
  while(test--){
    int num;
    scanf("%d",&num);
    if(num==1){
      printf("1\n");
    }
    else if(num==2){
      printf("1\n");
    }
    else if(num==3){
      printf("1\n");
    }
    else if(num==4){
      printf("2\n");
    }
    else{
      for(i=5; i<num+1; i++){
        dp[i]=dp[i-5]+dp[i-1];
      }
      printf("%lu\n",dp[i-1]);
    }
  }
  return 0;
}
