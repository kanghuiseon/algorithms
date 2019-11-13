#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <tuple>
using namespace std;
int main(){
  int num;
  scanf("%d",&num);
  while(num--){
    int n;
    int road[103][103];
    int check[103][103];
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    queue<tuple<int,int,int> > q;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        scanf("%1d",&road[i][j]);
      }
    }
    q.make_tuple(0,0,0);
    check[0][0]=1;
    while(!q.empty()){
      tuple<int,int,int> now = q.front();
      fir=get<0>(now);
      sec=get<1>(now);
      cnt=get<2>(now);
      q.pop()
      for(int t=0; t<4; t++){
        int n_x = fir + dx[t];
        int n_y = sec + dy[t];
        if(n_x<0 || n_x > n || n_y <0 || n_y > n)
          continue;
        if(check[n_x][n_y]!=0)
          continue;
        cnt = cnt + road[n_x][n_y];
        q.push(make_tuple(n_x,n_y,cnt));
        check[n_x][n_y] = 1;
      }
    }
  }
  return 0;
}
