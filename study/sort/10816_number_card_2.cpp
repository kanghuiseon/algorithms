#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
long long int n;
long long int m;
int cnt=0;
int main(){
  int number;
  scanf("%lld",&n);
  vector<int> v(n);
  for(int i=0; i<n; i++)
    scanf("%d",&v[i]);
  sort(v.begin(),v.end());
  scanf("%lld",&m);
  while(m--){
    int compare;
    scanf("%d", &compare);
    cout << upper_bound(v.begin(), v.end(),compare)-lower_bound(v.begin(),v.end(),compare) << " ";
  }
  printf("\n");
  return 0;
}
