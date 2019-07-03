#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <tuple>
using namespace std;
int fir, sec;
int main(){
  int maze[105][105]={0,};
  queue<tuple<int,int,int> > q;
  int check[105][105]={0,};
  int N,M,cnt=0;
  scanf("%d %d",&N, &M);
  for(int i=1; i<N+1; i++){
    for(int j=1; j<M+1; j++){
      scanf("%1d",&maze[i][j]);
    }
  }
  q.push(make_tuple(1,1,0));
  check[1][1]=1;
  while(!q.empty()){
    tuple<int, int, int> now = q.front();
    fir=get<0>(now);
    sec=get<1>(now);
    cnt=get<2>(now);
    q.pop();
    if(fir==N && sec==M){
        cout << get<2>(now)+1 << endl;
        break;
    }
    if(maze[fir][sec+1]==1 && check[fir][sec+1]==0){
        q.push(make_tuple(fir,sec+1,cnt+1));
        check[fir][sec+1]=1;
    }//right
    if(maze[fir+1][sec]==1 && check[fir+1][sec]==0){
      q.push(make_tuple(fir+1, sec,cnt+1));
      check[fir+1][sec]=1;
    }//down
    if(maze[fir-1][sec]==1 && check[fir-1][sec]==0){
      q.push(make_tuple(fir-1, sec,cnt+1));
      check[fir-1][sec]=1;
    }//up
    if(maze[fir][sec-1]==1 && check[fir][sec-1]==0){
      q.push(make_tuple(fir,sec-1, cnt+1));
      check[fir][sec-1]=1;
    }
  }
  return 0;
}
