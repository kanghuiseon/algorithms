#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_INDEX 100004
using namespace std;
int n, m;
int parent[MAX_INDEX];
int findRoot(int x){
    if(x == parent[x])
        return x;
    return parent[x] = findRoot(parent[x]);
}

void merge(int x, int y){
    x = findRoot(x);
    y = findRoot(y);
    if(x != y){
        parent[y] = x;
    }
}

bool checkSameRoot(int x, int y){
    x = findRoot(x);
    y = findRoot(y);
    if(x == y)
        return true;
    return false;
}
int main(){
    vector<pair<int, pair<int, int>>> arr;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr.push_back(make_pair(c, make_pair(a, b)));
        arr.push_back(make_pair(c, make_pair(b, a)));
    }
    int start, end;
    scanf("%d %d", &start, &end);
    for(int i=1; i<n+1; i++){
        parent[i] = i;
    }
    sort(arr.rbegin(), arr.rend());
    int answer = 0;
    for(int i=0; i<2*m; i++){
        int w = arr[i].first;
        int a = arr[i].second.first;
        int b = arr[i].second.second;
        
        if(!checkSameRoot(start, end)){
            merge(a, b);
            answer = w;
        }
        else{
            break;
        }
    }
    printf("%d\n", answer);
    return 0;
}

