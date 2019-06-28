#include <stdio.h>
#include <stdlib.h>

int main(){
  int cnt=0;
  int num,fir,sec,a;
  int sum=0;
  scanf("%d",&num); //26
  a = num;
  while(1){
    fir = num/10; //2
    sec = num%10; //6
    sum = (fir+sec)%10; //8
    num = sec*10+sum; //68
    cnt++;
    if(num==a)
      break;
  }
  printf("%d\n",cnt);
  return 0;
}
