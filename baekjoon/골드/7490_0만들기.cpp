#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int arr[20];

void dfs(int cnt, int num){
    if(num == cnt){
        int sum = 0;
        int n = 1;
        for(int i=2; i<=num; i++){
            if(arr[i] == '+'){
                sum += n;
                n = i;
            }else if(arr[i] == '-'){
                sum += n;
                n = -i;
            }
            else if(arr[i] == ' '){
                if(n > 0){
                    n = 10*n+i;
                }else{
                    n = 10*n-i;
                }
            }
        }
        sum += n;
        
        if(sum == 0){
            printf("1");
            for (int i = 2; i <= num; i++)
                printf("%c%d", arr[i], i);
            printf("\n");
        }
        return;
    }
    arr[cnt+1] = ' ';
    dfs(cnt+1, num);
    arr[cnt+1] = '+';
    dfs(cnt+1, num);
    arr[cnt+1]  = '-';
    dfs(cnt+1, num);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int num;
        cin >> num;
        dfs(1, num);
        cout << "\n";
    }
    return 0;
}
