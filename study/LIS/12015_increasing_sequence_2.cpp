#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int num;
  int seq[1000005];
  vector<int> dp;
  scanf("%d",&num);
  for(int i=0; i<num; i++){
    scanf("%d",&seq[i]);
  }
  for(int j=0; j<num; j++){
    auto inc = lower_bound(dp.begin(), dp.end(), seq[j]);
    if(inc == dp.end())
      dp.push_back(seq[j]);
    else
      dp[inc-dp.begin()] = seq[j];
  }
  printf("%lu",dp.size());
  return 0;
}
