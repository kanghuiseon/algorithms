#include <iostream>
#include <stack> //for DFS
#include <queue> //for BFS
#include <vector>
#include <algorithm> //for fill function
using namespace std;

int main(){
  int n, m, start;
  cin >> n >> m >> start;
  vector<int> list[n+1];
  bool check[n+1];
  fill(check, check+n+1, false);
  for(int i = 0; i<m; i++){
    int u, v;
    cin >> u >> v;

    list[u].push_back(v);
    list[v].push_back(u);
  }
  for(int i=1; i<=n; i++){
    sort(list[i].begin(), list[i].end());
  }

  dfs(start, list, check);
  printf("\n");
  return 0;
}
