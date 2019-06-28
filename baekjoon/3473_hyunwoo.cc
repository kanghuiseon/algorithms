#include <stdio.h>
#include <stdlib.h>

int main(){
  int num, input, fac=0;
  scanf("%d", &num);
  for(int i=0; i<num; i++){
    scanf("%d",&input);
    for(int j=5; j<=input; j*=5){
      fac+=input/j;
    }
    printf("%d\n",fac);
    fac=0;
  }
  return 0;
}
