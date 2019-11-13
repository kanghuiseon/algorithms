#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	int arr[3]={0,};
	int Max[2][3]={0,};
	int Min[2][3]={0,};
	int num,a,b,c, max_, min_;
	scanf("%d",&num);
	scanf("%d %d %d",&a,&b,&c);
	Max[0][0]=a,Max[0][1]=b,Max[0][2]=c;
	Min[0][0]=a,Min[0][1]=b,Min[0][2]=c;
	for(int i=0; i<num-1; i++){
		scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
		Max[1][0] = max(Max[0][0]+arr[0],Max[0][1]+arr[0]);
		Max[1][1] = max(max(Max[0][0]+arr[1],Max[0][1]+arr[1]),Max[0][2]+arr[1]);
		Max[1][2] = max(Max[0][1]+arr[2],Max[0][2]+arr[2]);

		Min[1][0] = min(Min[0][0]+arr[0],Min[0][1]+arr[0]);
		Min[1][1] = min(min(Min[0][0]+arr[1],Min[0][1]+arr[1]),Min[0][2]+arr[1]);
		Min[1][2] = min(Min[0][1]+arr[2],Min[0][2]+arr[2]);

    for(int j=0; j<3; j++){
      Min[0][j] = Min[1][j];
      Max[0][j] = Max[1][j];
    }
	}
	max_ = max(max(Max[0][0],Max[0][1]),Max[0][2]);
	min_ = min(min(Min[0][0],Min[0][1]),Min[0][2]);
	printf("%d %d\n",max_,min_);
	return 0;
}
