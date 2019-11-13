#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int jewelry[300005];
int main(){
  int stu, jnum;
  int total=0, start=0, end=0;
  scanf("%d %d",&stu, &jnum);
  for(int i=0; i<jnum; i++){
    scanf("%d",&jewelry[i]);
    end = max(end, jewelry[i]);
    total += jewelry[i];
  }
  int ans=987654321;
  while(start <= end){
    int mid = (start + end) / 2;
    int people = 0;
    for(int i=0; i<jnum; i++){
      int div = jewelry[i] / mid;
      int rem = jewelry[i] % mid;
      if(!rem)
        people += div;
      else
        people += div + 1;
    }
    if(people > stu)
      start = mid+1;
    else{
      end = mid-1;
      ans = min(ans, mid);
    }
  }
  printf("%d\n",ans);
  return 0;
}
