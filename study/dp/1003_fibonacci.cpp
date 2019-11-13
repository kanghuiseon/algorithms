#include <iostream>
#include <stdio.h>
int fibo[43]={0,};
int fibon(int num){
  if()
}
int main(){
  int test,num;
  scanf("%d",&test);
  while(test--){
    scanf("%d",&num);
    if(num == 0)
      printf("1 0\n");
    else if(num == 1)
      printf("0 1\n");
    else{
      fibon(num);
      printf("%d %d\n",fibo[num-2],fibo[num-1]);
    }
  }
}
