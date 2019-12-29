#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  int arr[10] = {0,};
  int aa = -1;

  for(int i = 1; i <= N; i++){
    int tmp = i;
    while(tmp > 0){
      aa = tmp % 10;
      arr[aa]++;
      tmp = tmp / 10;
    }
  }


  for(int i = 0; i < 10; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
