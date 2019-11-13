#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
  int seq[1005];
  int Length[1005];
  int Max=0,n;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&seq[i]);
  }
  for(int t=0; t<n; t++)
    Length[t] = 1;
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      if((seq[i]>seq[j]) && (Length[i]>=Length[j]))
        Length[j] = Length[i]+1;
    }
  }
  for(int k=0; k<n; k++){
    if(Max < Length[k])
      Max = Length[k];
  }
  printf("%d\n", Max);
  return 0;
}
