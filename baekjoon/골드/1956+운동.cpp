#include <iostream>
#include <algorithm>
#include <string>
#define MAX_INDEX 401
#define MAX 200000
using namespace std;
int v, e;
int arr[MAX_INDEX][MAX_INDEX];
int main(){
    scanf("%d %d", &v, &e);
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            arr[i][j] = MAX;
        }
    }
    for(int i=0; i<e; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = c;
    }
    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    int Min = MAX;
    for(int i=1; i<=v; i++){
        if(arr[i][i] == MAX)
            continue;
        if(Min > arr[i][i]){
            Min = arr[i][i];
        }
    }
    if(Min == MAX){
        printf("-1\n");
    }else{
        printf("%d\n", Min);
    }
    return 0;
}
