#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(v[i][k] && v[k][j])
                    v[i][j] = 1;
            }
        }
    }
    for(auto a: v){
        for(auto b: a){
            printf("%d ", b);
        }
        printf("\n");
    }
    return 0;
}
