#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  int line[205]={0,};
  int Check[205] = {0,};
  int kids,max=0;
  scanf("%d",&kids);
  for(int i=0; i<kids; i++){
    scanf("%d",&line[i]);
  }
  for(int k=0; k<kids; k++){
    Check[k]=1;
  }
  for(int i=0; i<kids-1; i++){
    for(int j=i+1; j<kids; j++){
      if((line[i]<line[j])&&Check[i]>=Check[j]){
        Check[j] = Check[i]+1;
      }
    }
  }
  for(int t=0; t<kids; t++){
    if(max<Check[t])
      max = Check[t];
  }
  printf("%d\n",kids-max);
  return 0;
}
