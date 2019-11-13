#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int road[103][103]={0,};
int check[103][103]={0,};
queue<pair<int, int> > q;
void dfs(int f){
  
}
int main(){
  int num;
  scanf("%d",&num);
  for(int i=1; i<num+1; i++){
    for(int j=1; j<num+1; j++){
      scanf("%d",&road[i][j]);
      if(road[i][j]==1){
        check[i][j]=1;
        q.push(make_pair(i,j));
      }
    }
  }
  while(!q.pop()){
    pair<int, int> new_ = q.front();
    int fir = new_.first;
    q.pop();
    dfs(fir);
  }
  for(int l=1; l<num+1; l++){
    for(int t=1; t<num+1; t++){
      printf("%d ",check[l][t]);
    }
    printf("\n");
    }
  return 0;
}
