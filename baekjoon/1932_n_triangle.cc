#include <iostream>
using namespace std;
int tri[505][505];
int main(){
  int N;
  int Max=-1;
  scanf("%d",&N);
  for(int i=1; i<=N; i++){
    for(int j=1; j<=i; j++){
      scanf("%d",&tri[i][j]);
    }
  }
  for(int i=2; i<=N; i++){
    for(int j=1; j<=i; j++){
      if(j==1)
        tri[i][j] += tri[i-1][j];
      else if(i == j)
        tri[i][j] += tri[i-1][j-1];
      else
        tri[i][j] = max(tri[i][j]+tri[i-1][j-1], tri[i][j]+tri[i-1][j]);
    }
  }
  for(int i=1; i<=N; i++){
    for(int j=1; j<=i; j++){
      printf("%d",tri[i][j]);
    }
    printf("\n");
  }

  for(int i=1; i<=N; i++){
    Max = max(Max,tri[N][i]);
  }
  printf("%d\n",Max);
  return 0;
}
