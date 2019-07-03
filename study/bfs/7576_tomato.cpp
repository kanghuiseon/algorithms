#include <iostream>
#include <queue>
#include <tuple>
#include <stdio.h>
using namespace std;
int main(){
  int M,N;
  queue<tuple<int, int, int> > q;
  int box[1005][1005]={0,};
  int check[1005][1005]={0,};
  scanf("%d %d",&M,&N);
  for(int i=1; i<M+1; i++){
    for(int j=1; j<N+1; j++){
      scanf("%d",&maze[i][j]);
    }
  }

}
