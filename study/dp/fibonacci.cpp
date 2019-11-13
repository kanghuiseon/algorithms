#include <iostream>
#include <stdio.h>
using namespace std;
int fibo[43];
int num_of_zero(int num){
  int cnt=0;
  long long int a;
  if(num == 0)
    return 1;
  else if(num==1)
    return 0;
  else{
    for(int i=0; i<=num; i++){
      a = fibo[i];
      if(a==0){
        cnt++;
        continue;
      }
      while(a>0){
        if((a%10)==0)
          cnt++;
        a = a/10;
      }
    }
  }
  return cnt;
}
int num_of_one(int num){
  int cnt=0;
  long long int a;
  if(num == 1)
    return 1;
  else{
    for(int i=0; i<=num; i++){
      a = fibo[i];
      if(a==1){
        cnt++;
        continue;
      }
      while(a>0){
        if((a%10)==1)
          cnt++;
        a = a/10;
      }
    }
  }
  return cnt;
}
int main(){
  int n, zero=0, one=0, test;
  scanf("%d",&test);
  while(test--){
    scanf("%d", &n);
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2; i<=n; i++){
      fibo[i]=fibo[i-1]+fibo[i-2];
    }
    zero = num_of_zero(n);
    one = num_of_one(n);
    printf("%d %d\n",zero, one);
  }
  return 0;
}
