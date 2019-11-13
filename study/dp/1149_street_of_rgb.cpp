#include <iostream>
#include <algorithm>
using namespace std;
int num;
int cost[3]={0,};
int minCost(){
  int rgb[3];
  int r,g,b;
  cin >> r >> g >> b;
  rgb[0] = r, rgb[1] = g, rgb[2] = b;
  for(int i=1; i<num; i++){
    cin >> r >> g >> b;
    for(int i=0; i<num; i++)
      cost[i] = rgb[i];
    rgb[0] = r + min(cost[1], cost[2]);
    rgb[1] = g + min(cost[0], cost[2]);
    rgb[2] = b + min(cost[0], cost[1]);
  }
  return (rgb[0]>rgb[1] ? (rgb[1]>rgb[2] ? rgb[2] : rgb[1]) : rgb[0]>rgb[2] ? rgb[2] : rgb[0]);
}
int main(){
  cin>>num;
  cout << minCost() << endl;
  return 0;
}
