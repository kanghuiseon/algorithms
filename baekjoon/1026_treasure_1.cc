#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void selection_sort_min(int list[], int n){
  int min=0;
  int i,j,temp=0;
  for(i=0; i<n-1; i++){
    min=i;
    for(j=i+1; j<n; j++){
      if(list[j]<list[min]){
        min = j;
      }
    }
    SWAP(list[i],list[min],temp);
  }
}

void selection_sort_max(int list[], int n){
  int max=0;
  int temp=0;
  for(int i=0; i<n-1; i++){
    max=i;
    for(int j=i+1; j<n; j++){
      if(list[j]>list[max]){
        max = j;
      }
    }
    SWAP(list[i],list[max],temp);
  }

}

int main() {
  int num, sum=0;
  int a[100];
  int b[100];
  int i, j ;
  scanf("%d",&num);
  for(i=0; i<num; i++){
    scanf("%d",&a[i]);
  }
  for(j=0; j<num; j++){
    scanf("%d",&b[j]);
  }
  selection_sort_min(a, num);
  selection_sort_max(b, num);

  for(int k=0; k<num; k++){
    sum += a[k]*b[k];
  }
  printf("%d", sum);

  return 0;
}
