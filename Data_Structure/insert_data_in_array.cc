#include <stdio.h>
#include <stdlib.h>

int main(){
    char data[5] = {'a', 'b', 'd', 'e'};
    char c = 'c';
    int i, tmp, tmp2;

    for(i=0; i<5; i++){
      printf("%2c",data[i]);
    }
    printf("\n");

    for(i=0; i<5; i++){
      if(data[i]> c){
        break;
      }
    } //i=2
    tmp = data[i]; //tmp=d
    data[i] = c; //data[3] = c data[]={'a','b','c','e'}
    i++; //i=3;

    for(; i<5; i++){
      tmp2 = data[i]; //tmp2 = e
      data[i] = tmp; //i = 3 : data[]={'a','b','c','d'}
      tmp = tmp2;
    }

    for(i=0; i<5; i++){
      printf("%2c", data[i]);
    }

    printf("\n");
    return 0;
}
