#include <stdio.h>
#include <stdlib.h>
int Rev(int a){
  int sum=0;
  while(a>0){
    sum*=10;
    sum += a%10;
    a/=10;
  }
  return sum;
}
int main(){
  int x, y;
  scanf("%d %d",&x,&y);
  printf("%d\n",Rev(Rev(x)+Rev(y)));
  return 0;
}
