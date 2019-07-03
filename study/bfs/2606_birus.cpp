#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main(){
    queue<int> p;
    int cnt=0,node,edge,a,b,first=1,now;
    int arr[105][105]={0,};
    int check[105]={0,};
    cin>>node;
    cin>>edge;
    for(int i=1; i<edge+1; i++){
      cin>> a >> b;
      arr[a][b]=1;
      arr[b][a]=1;
    }
    p.push(first);
    check[first]=1;
    while(!p.empty()){
      now=p.front();
      p.pop();
      for(int j=1; j<node+1; j++){
        if(arr[now][j]==1 && check[j]==0){
          p.push(j);
          check[j]=1;
          cnt++;
        }
      }
    }
    cout << cnt << endl;

}
