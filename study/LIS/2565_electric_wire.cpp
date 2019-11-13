#include <stdio.h>
#include <string.h>
int main(){
  int n,Max=0,i,j,k,m,t;
  int Length[505]={0,};
  int seq[505]={0,};
  scanf("%d",&n);
  for(i=0; i<n; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    seq[a]=b;
  }
  for(i=1; i<505; i++)
    Length[i]=1;
  for(m=1; m<505; m++){
    for(j=m+1; j<505; j++){
      if(seq[m]==0)
        continue;
      else if((seq[m]<seq[j]) && (Length[m]>=Length[j]))
         Length[j] = Length[m]+1;
      else
        continue;
      }
  }
  for(k=1; k<505; k++){
    if(Max < Length[k])
      Max = Length[k];
  }
  printf("%d\n",n-Max);
  return 0;
}
