#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  int n,Max=0,k,index=0,cnt=0;
  int Length[1005];
  int seq[1005];
  int arr[1005];
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&seq[i]);
  }
  for(int i=0; i<n; i++){
    Length[i]=1;
  }

  for(int m=0; m<n-1; m++){
    for(int j=m+1; j<n; j++){
      if((seq[m]<seq[j]) && (Length[m]>=Length[j]))
         Length[j] = Length[m]+1;
      else
        continue;
      }
  }
  for(k=0; k<n; k++){
    if(Max < Length[k]){
      Max = Length[k];
      index=k;
    }
  }

  printf("%d\n",Max);
  arr[Max]=seq[index];
  cnt = Max;
  Max -= 1;
  for(int t=index-1; t>=0; t--){
    if((Length[t]==Max) && (seq[t]<seq[index])){
      index=t;
      arr[Max] = seq[t];
      Max -= 1;
      if(Max==0)
        break;
    }
  }
  for(int l=1; l<cnt+1; l++){
    printf("%d ",arr[l]);
  }
  printf("\n");
  return 0;
}
