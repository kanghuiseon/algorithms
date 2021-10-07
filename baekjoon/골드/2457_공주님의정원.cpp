#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> flowers;
    int cnt = 0;
    for(int i=0; i<n; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int start = a*100 + b;
        int end = c*100 + d;
        flowers.push_back(make_pair(start, end));
    }
    if(flowers[0].first > 301){
        printf("0\n");
        return 0;
    }
    sort(flowers.begin(), flowers.end());
    int end = 301;
    int end2 = 0;
    int idx = 0;
    bool resultFlag = false;
    while(end <= 1130 && idx < n){
        bool flag = false;
        for(int i=idx; i<n; i++){
            if(flowers[i].first <= end){
                if(end2 < flowers[i].second){
                    end2 = flowers[i].second;
                    flag = true;
                    idx = i;
                }
            }else{
                break;
            }
        }
        if(!flag){
            resultFlag = true;
            break;
        }
            
        end = end2;
        cnt++;
    }
    if(!resultFlag)
        printf("%d\n", cnt);
    else
        printf("0\n");
    return 0;
}
