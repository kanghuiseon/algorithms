#include <stdio.h>
#include <stdlib.h>

int main(){
  int E=0,S=0,M=0,e,s,m,sum=0;
  scanf("%d %d %d", &e,&s,&m);
  while(1){
    E++;
    S++;
    M++;
    sum++;
    if(E==16) E=1;
    if(S==29) S=1;
    if(M==20) M=1;
    if(E==e && S==s && M==m)
      break;
  }
  printf("%d\n",sum);
  return 0;
}
