#include <string>
#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000000000
using namespace std;

int main(){
    long long int n;
    long long int sum = 0;
    cin >> n;
    vector<long long int> km(n-1);
    vector<long long int> price(n);
    long long int Min = MAX;
    for(int i=0; i<n-1; i++){
        cin >> km[i];
    }
    for(int i=0; i<n; i++){
        cin >> price[i];
    }
    for(int i=0; i<n-1; i++){
        if(price[i] < Min){
            Min = price[i];
        }
        sum += Min * km[i];
    }
    printf("%lld\n", sum);
    return 0;
}
