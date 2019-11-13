#include <algorithm>
#include <iostream>
using namespace std;
long long int card[500005];
int BS(int left, int right, int num){
  int mid = (left+right)/2;
  if(left <= right){
    if(num < card[mid]){
      right = mid-1;
      return BS(left, right, num);
    }
    else if(num > card[mid]){
      left = mid+1;
      return BS(left,right,num);
    }
    else{
      return 1;
    }
  }
    return 0;
}
int main(){
  long long int N,M,check,num;
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    scanf("%lld", &card[i]);
  }
  sort(card, card+N);
  scanf("%d",&M);
  while(M!=0){
    scanf("%d",&num);
    cout << BS(0,N-1,num) << " ";
    M--;
  }
  printf("\n");
  return 0;
}
