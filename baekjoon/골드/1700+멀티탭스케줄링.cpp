#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[103];
int multi[103];
int main() {
    int n, k;
    int cnt = 0;
    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<k; i++){
        bool flag = false;
        // 현재 멀티탭에 꽂혀있는지 체크
        for(int j=0; j<n; j++){
            if(multi[j] == arr[i]){
                flag = true;
                break;
            }
        }
        // true면 꽂혀있다.
        if(flag)
            continue;
        
        // 빈 곳 체크
        for(int j=0; j<n; j++){
            // 빈 곳이 있으니까 거기에 넣기
            if(multi[j] == 0){
                multi[j] = arr[i];
                flag = true;
                break;
            }
        }
        // true면 빈 곳에 꽂았다.
        if(flag)
            continue;
        int lastIdx[103] = {0,};
        // 앞으로 사용안하거나, 제일 나중에 사용할 플러그 빼기
        for(int j=i+1; j<k; j++){
            for(int l=0; l<n; l++){
                if(arr[j] == multi[l]){
                    if(lastIdx[l] == 0)
                        lastIdx[l] = j;
                }
            }
        }
        int Max=-1, MaxIdx=-1;
        for(int j=0; j<n; j++){
            if(lastIdx[j] == 0){
                MaxIdx = j;
                break;
            }else{
                if(Max < lastIdx[j]){
                    Max = lastIdx[j];
                    MaxIdx = j;
                }
            }
        }
        multi[MaxIdx] = arr[i];
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
