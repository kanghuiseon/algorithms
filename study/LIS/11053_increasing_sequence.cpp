#include <stdio.h>
#include <string.h>
int main(){
  int n,Max=0,i,j,k,m,t;
  int Length[1005];
  int seq[1005];
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&seq[i]);
  }
  for(i=0; i<n; i++)
    Length[i]=1;
  for(m=0; m<n-1; m++){
    for(j=m+1; j<n; j++){
      if((seq[m]<seq[j]) && (Length[m]>=Length[j]))
         Length[j] = Length[m]+1;
      else
        continue;
      }
  }
  for(k=0; k<n; k++){
    if(Max < Length[k])
      Max = Length[k];
  }
  printf("%d\n",Max);
  return 0;
}
