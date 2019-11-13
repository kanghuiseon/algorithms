#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  int people[4];
  int sum=0,Max=0;
  for(int i=0; i<4; i++){
    int a,b;
    scanf("%d %d",&a, &b);
    sum-=a;
    sum+=b;
    people[i]=sum;
  }
  for(int j=0; j<4; j++){
    if(Max < people[j])
      Max = people[j];
  }
  printf("%d\n",Max);
  return 0;
}
