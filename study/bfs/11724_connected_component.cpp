#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main(){
    queue<int> p;
    int arr[1005][1005] = {0,};
    int check[1005]={0,};
    int node, edge, now, cnt=0,total;
    int a,b;
    cin >> node >> edge;
    total = node;
    for(int i=0; i<edge; i++){
      cin >> a >> b;
      arr[a][b]=1;
      arr[b][a]=1;
    }

    for(int j=1; j<1005; j++){
      if(check[j]==1) continue;
      p.push(j);
      total--;
      check[j]=1;
      cnt++;
      while(!p.empty()){
        now = p.front();
        p.pop();
        for(int i=1; i<node+1; i++){
          if(arr[now][i]==1 && !check[i]){
            check[i]=1;
            p.push(i);
            total--;
          }
        }

      }
      if(total==0)
        break;
    }
    cout << cnt << "\n";
    return 0;
}
