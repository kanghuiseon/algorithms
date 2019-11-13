#include <iostream>
#include <queue>
using namespace std;
int M, N, K;
int baechoo[55][55];
int dirx[4] = {0,0,1,-1};
int diry[4] = {1,-1,0,0};
void dfs(int x, int y){
  baechoo[x][y] = 0;
  for(int i=0; i<4; i++){
    int nextx = x + dirx[i];
    int nexty = y + diry[i];
    if(nextx<0 || nextx>N || nexty<0 || nexty > M)
      continue;
      if(baechoo[nextx][nexty] == 0)
        continue;
      dfs(nextx, nexty);
  }
}
int main(){
  int test;
  scanf("%d",&test);
  while(test--){
    int earthworm=0;
    scanf("%d %d %d",&M,&N,&K);
    for(int k=0; k<K; k++){
      int x,y;
      scanf("%d %d",&y,&x);
      baechoo[x][y] = 1;
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(baechoo[i][j] != 0){
          earthworm++;
          dfs(i,j);
        }
      }
    }
    printf("%d\n",earthworm);
  }
  return 0;
}
