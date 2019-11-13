#include <iostream>
int main(){
  int N;
  scanf("%d",&N);
  long long int n[95];
  n[0]=0; n[1]=1;
  for(int i=2; i<=N; i++)
    n[i]=n[i-1]+n[i-2];
  printf("%lld\n", n[N]);
  return 0;
}
