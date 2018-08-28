#include <iostream>
#include <queue> //for BFS
#include <cstring>
using namespace std;
const int MAX = 1000 + 1;

int n, m, start;
bool check[MAX];
int graph[MAX][MAX]; //for dfs, bfs
queue<int> q; //for bfs
//the fuction of DFS
void dfs(int start){
    cout << start << " ";
    for(int i=1; i<=n; i++){
      if(graph[start][i] && !check[i])
        check[i] = 1;
        dfs(i);
      }
    }

}
//the fuction of BFS
void bfs(int start){
  q.push(start);
  check[start]=1;
  while(!q.empty()){
    start = q.front();
    q.pop();
    cout << start << " ";
    for(int i=1; i<=n; i++){
      if(graph[start][i] && !check[i]){
        check[i] = 1;
        q.push(i);
      }
    }
  }

}

int main(){
  cin >> n >> m >> start;

  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    graph[u][v]=1;
    graph[v][u]=1;
  }

  check[start]=1;
  dfs(start);
  cout << endl;

  memset(check, false, sizeof(check));
  bfs(start);
  cout << endl;


  return 0;
}
