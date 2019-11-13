#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int main(){
  int test,n,m,num;
  scanf("%d",&test);
  while(test--){
    int count=0;
    scanf("%d %d",&n,&m);
    queue<pair<int, int> > q;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
      scanf("%d",&num);
      q.push(make_pair(i,num));
      pq.push(num);
    }
    while(!q.empty()){
      int fir = q.front().first;
      int sec = q.front().second;
      q.pop();
      if(pq.top() == sec){
        pq.pop();
        count++;
        if(fir == m){
          printf("%d\n",count);
          break;
        }
      }
      else
        q.push(make_pair(fir, sec));
    }
  }
  return 0;
}
