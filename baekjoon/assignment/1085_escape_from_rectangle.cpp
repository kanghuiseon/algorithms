#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int main(){
  int x,y,w,h;
  vector<int> arr;
  scanf("%d %d %d %d",&x,&y,&w,&h);
  if(w>1000 && h>1000)
    return 0;
  if(x<1 || x>w-1)
    return 0;
  if(y<1 || y>h-1)
    return 0;
  arr.push_back(x);
  arr.push_back(y);
  arr.push_back(w-x);
  arr.push_back(h-y);
  sort(arr.begin(),arr.end());
  printf("%d\n",arr[0]);
  return 0;
}
