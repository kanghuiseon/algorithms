#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
  int maze[105][105]={0,};
  queue<pair<int,int> > q;
  int check[105][105]={0,};
  int N,M,fir,sec,cnt=1;
  scanf("%d %d",&N, &M);
  for(int i=1; i<N+1; i++){
    for(int j=1; j<M+1; j++){
      scanf("%1d",&maze[i][j]);
    }
  }
  q.push(make_pair(1,1));
  check[1][1]=1;
  while(!q.empty()){
    pair<int,int> now = q.front();
    q.pop();
    fir=now.first;
    sec=now.second;
    if(maze[fir][sec+1]==1 && check[fir][sec+1]==0){
        q.push(make_pair(fir,sec+1));
        check[fir][sec+1]=cnt+1;
    }//right
    if(maze[fir+1][sec]==1 && check[fir+1][sec]==0){
      q.push(make_pair(fir+1, sec));
      check[fir+1][sec]=cnt+1;
    }//down
    if(maze[fir-1][sec]==1 && check[fir-1][sec]==0){
      q.push(make_pair(fir-1, sec));
      check[fir-1][sec]=cnt+1;
    }//up
  }
  cout << check[N][M]-1 << endl;
  return 0;
}
