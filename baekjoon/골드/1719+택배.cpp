#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX_INDEX 202
#define MAX 300000
using namespace std;
int n, m;
int arr[MAX_INDEX][MAX_INDEX];
int factory[MAX_INDEX][MAX_INDEX];
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
                arr[i][j] = MAX;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        arr[a][b] = x;
        arr[b][a] = x;
        factory[a][b] = b;
        factory[b][a] = a;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                    if(arr[i][k] != MAX){
                        factory[i][j] = factory[i][k];
                    }else{
                        factory[i][j] = k;
                    }
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                printf("- ");
            else
                printf("%d ", factory[i][j]);
        }
        printf("\n");
    }
    return 0;
}
