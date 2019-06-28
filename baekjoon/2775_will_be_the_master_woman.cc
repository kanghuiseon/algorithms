#include <stdio.h>

int floor_n[15][15];

int main(){
  int num,k,n;
  scanf("%d",&num);


  for(int i=1; i<15; i++){
    floor_n[0][i]=i;
  }
  for(int j=1; j<15; j++){
    for(int k=1; k<15; k++){
      floor_n[j][k] = floor_n[j-1][k]+floor_n[j][k-1];
    }
  }

  for(int t=0; t<num; t++){
    scanf("%d",&k);
    scanf("%d",&n);
    printf("%d\n",floor_n[k][n]);
  }
  return 0;
}
