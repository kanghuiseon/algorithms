#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<vector<int>> v(16, vector<int>(16, 0));
int Min = 0x7fffffff;
int n;
int mp, mf, ms, mv;
int check[16];
vector<vector<int>> answer;
int cal(vector<int> arr){
    int price = 0;
    int p=0, f=0, s=0, vv=0;
    for(int i=0; i<arr.size(); i++){
        p += v[arr[i]][0];
        f += v[arr[i]][1];
        s += v[arr[i]][2];
        vv += v[arr[i]][3];
        price += v[arr[i]][4];
    }
    if(p < mp || f < mf || s < ms || vv < mv){
        return -1;
    }
    return price;
}
void dfs(int cnt, int limit, int idx, vector<int> arr){
    if(cnt == limit){
        int price = cal(arr);
        if(price == -1){
            return;
        }
        if(Min > price){
            Min = price;
            answer.clear();
            answer.push_back(arr);
        }
        else if(Min == price){
            answer.push_back(arr);
        }
        return;
    }
    for(int i=idx; i<n; i++){
        if(check[i] == 1){
            continue;
        }
        check[i] = 1;
        vector<int> tmp = arr;
        tmp.push_back(i);
        dfs(cnt+1, limit, i, tmp);
        check[i] = 0;
    }
}
int main() {
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            int tmp;
            cin >> tmp;
            v[i][j] = tmp;
        }
    }
    for(int i=1; i<=n; i++){
        dfs(0, i, 0, {});
        memset(check, 0, sizeof(check));
    }
    if(Min == 0x7fffffff){
        printf("-1\n");
        printf("\n");
    }else{
        printf("%d\n", Min);
        sort(answer.begin(), answer.end());
        for(int i=0; i<answer[0].size(); i++){
            printf("%d ", answer[0][i]+1);
        }
        printf("\n");
    }
    return 0;
}
