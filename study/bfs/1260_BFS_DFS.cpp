#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int arr[1005][1005] = {0,};
int check[1005];
queue<int> p;
int node, edge, first,now;
int a,b;

void BFS(int first){
  p.push(first);
  check[first]=1;
  while(!p.empty()){
    now = p.front();
    p.pop();
    cout << now << " ";
    for(int i=1; i<node+1; i++){
      if(arr[now][i]==1 && !check[i]){
        check[i]=1;
        p.push(i);
      }
    }
  }
}
void DFS(int first){
  cout << first << " ";
  check[first]=1;
  for(int i=1; i<node+1; i++){
    if(arr[first][i]==1 && check[i]==0){
      check[i]=1;
      DFS(i);
    }
  }
  }

int main(){
    cin >> node >> edge >> first;
    for(int i=0; i<edge; i++){
      cin >> a >> b;
      arr[a][b]=1;
      arr[b][a]=1;
    }
    DFS(first);
    cout << "\n";
    memset(check, false, sizeof(check));
    BFS(first);
    cout << "\n";
    return 0;
}
