#include <iostream>
#include <queue>
#include <tuple>
#include <stdio.h>
#include <string.h>
using namespace std;
int day;
int main(){
  queue<tuple<int, int, int> > q;
  int dx[4] = {-1,1,0,0};
  int dy[4] = {0,0,1,-1};
  int box[1005][1005];
  for(int z=0; z<1005; z++){
    memset(box[z],3,sizeof(int)*1005);
  }
  int check[1005][1005]={0,};
  int M,N,fir,sec,next_fir=0, next_sec=0;
  scanf("%d %d",&M,&N);
  for(int i=1; i<N+1; i++){
    for(int j=1; j<M+1; j++){
      scanf("%d",&box[i][j]);
      if(box[i][j]==1) //box에 1이면 queue에 넣기
        q.push(make_tuple(i,j,0));
    }
  }
 while(!q.empty()){
    tuple<int, int, int> now = q.front();
    fir = get<0>(now);
    sec = get<1>(now);
    day = get<2>(now);
    q.pop();
    for(int d=0; d<4; d++){
      //d=0:up, d=1:down, d=2:right, d=3:left
      next_fir = fir + dx[d];
      next_sec = sec + dy[d];
      //if box is empty and no check, change values of both box and check to 1.
      if(box[next_fir][next_sec]==0 && check[next_fir][next_sec]==0){
        box[next_fir][next_sec]=1;
        check[next_fir][next_sec]=1;
        q.push(make_tuple(next_fir, next_sec, day+1));
      }
    }
  }
  for(int i=1; i<N+1; i++){
    for(int j=1; j<M+1; j++){
      if(box[i][j]==0 && check[i][j]==0)
        day=-1;
    }
  }
  cout<<day<<endl;
  return 0;
}
