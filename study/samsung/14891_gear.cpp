#include <iostream>
#include <stdio.h>
using namespace std;
void counter_clock(int arr[]){
  int num = arr[0];
  for(int i=0; i<7; i++)
    arr[i] = arr[i+1];
  arr[7] = num;
}
void clock_(int arr[]){
  int num = arr[7];
  for(int i=7; i>0; i--)
    arr[i] = arr[i-1];
  arr[0] = num;
}
int main(){
  int k,sum=0;
  int gear1[8]={0,};
  int gear2[8]={0,};
  int gear3[8]={0,};
  int gear4[8]={0,};
  for(int i=0; i<8; i++)
    scanf("%1d",&gear1[i]);
  for(int i=0; i<8; i++)
    scanf("%1d",&gear2[i]);
  for(int i=0; i<8; i++)
    scanf("%1d",&gear3[i]);
  for(int i=0; i<8; i++)
    scanf("%1d",&gear4[i]);
  scanf("%d",&k);
  for(int i=0; i<k; i++){
    int gear_num, dir;
    int num1 = gear1[2], num2 = gear2[6], num3 = gear2[2], num4 = gear3[6], num5 = gear3[2], num6 = gear4[6];
    scanf("%d %d",&gear_num, &dir);
    switch(gear_num){
      case 1:
        if(dir == 1){
          clock_(gear1);
          if(num1 != num2){
            counter_clock(gear2);
            if(num3 != num4){
              clock_(gear3);
              if(num5 != num6)
                counter_clock(gear4);
            }
          }
        }
        else if(dir == -1){
          counter_clock(gear1);
          if(num1 != num2){
            clock_(gear2);
            if(num3 != num4){
              counter_clock(gear3);
              if(num5 != num6)
                clock_(gear4);
            }
          }
        }
        break;
      case 2:
        if(dir == 1){
          clock_(gear2);
          if(num1 != num2)
            counter_clock(gear1);
          if(num3 != num4){
            counter_clock(gear3);
              if(num5 != num6)
                clock_(gear4);
          }
        }
        else if(dir == -1){
          counter_clock(gear2);
          if(num1 != num2)
            clock_(gear1);
          if(num3 != num4){
            clock_(gear3);
            if(num5 != num6){
              counter_clock(gear4);
            }
          }
        }
        break;
      case 3:
        if(dir == 1){
          clock_(gear3);
          if(num3 != num4){
            counter_clock(gear2);
            if(num1 != num2)
              clock_(gear1);
          }
          if(num5 != num6)
            counter_clock(gear4);
        }
        else if(dir == -1){
          counter_clock(gear3);
          if(num3 != num4){
            clock_(gear2);
            if(num1 != num2){
              counter_clock(gear1);
            }
          }
          if(num5 != num6)
            clock_(gear4);
        }
        break;
      case 4:
        if(dir == 1){
          clock_(gear4);
          if(num5 != num6){
            counter_clock(gear3);
            if(num3 != num4){
              clock_(gear2);
              if(num1 != num2)
                counter_clock(gear1);
            }
          }
        }
        else if(dir == -1){
          counter_clock(gear4);
          if(num5 != num6){
            clock_(gear3);
            if(num3 != num4){
              counter_clock(gear2);
              if(num1 != num2)
                clock_(gear1);
            }
          }
        }
        break;
    }
  }
  if(gear1[0]==1)
    sum+=1;
  if(gear2[0]==1)
    sum+=2;
  if(gear3[0]==1)
    sum+=4;
  if(gear4[0]==1)
    sum+=8;
  printf("%d\n",sum);
  return 0;
}
