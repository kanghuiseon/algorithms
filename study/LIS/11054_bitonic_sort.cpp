#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
  int n,max_=0;
  int Length[1005];
  int Length_[1005];
  int seq_fir[1005];
  int seq_sec[1005];
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&seq_fir[i]);
  }
  for(int w=0; w<n; w++)
    seq_sec[w] = seq_fir[w];
  for(int i=0; i<n; i++){
    Length[i]=1;
    Length_[i]=1;
  }
  for(int m=0; m<n-1; m++){
    for(int j=m+1; j<n; j++){
      if((seq_fir[m]<seq_fir[j]) && (Length[m]>=Length[j]))
         Length[j] = Length[m]+1;
      else
        continue;
      }
  }
  for(int l=n-1; l>0; l--){
    for(int t= l-1; t>=0; t--){
      if((seq_sec[l]<seq_sec[t]) && (Length_[l]>=Length_[t]))
        Length_[t] = Length_[l]+1;
      else
        continue;
    }
  }
  for(int t=0; t<n; t++){
    if(max_ < Length[t]+Length_[t])
      max_ = Length[t]+Length_[t];
  }
  printf("%d\n",max_-1);
  return 0;
}
