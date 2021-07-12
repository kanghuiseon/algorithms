#include <stdio.h>
#define MAX 10001
using namespace std;
bool list[MAX];

int Sum(int n){
  int sum=n;
  while(1){
    if(n==0){
      break;
    }
    sum += n%10;
    n = n/10;
  }
  return sum;
}


int main(){
  int num;
  for(int i=1; i<MAX; i++){
    num = Sum(i);
    if(num<=MAX){
      list[num]=true;
    }
  }
  for(int j=1; j<MAX; j++)
  {
    if(!list[j]){
      printf("%d\n", j);
    }
  }
  return 0;
}

