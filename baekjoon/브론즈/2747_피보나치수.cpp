#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num;
    scanf("%d", &num);
    int a=0, b=1;
    int tmp_a =0, tmp_b=0;
    while(num--){
        tmp_a = a;
        tmp_b = b;
        b = a+b;
        a = tmp_b;
    }
    printf("%d\n", a);
    return 0;
}

