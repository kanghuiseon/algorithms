#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool comp(pair<int, int>& a, pair<int, int>& b){
    if(a.second == b.second)
        return a.first < b.first;
    else{
        return a.second < b.second;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v(n+1, 0);
        vector<pair<int, int>> books;
        int cnt = 0;
        while(m--){
            int a, b;
            cin >> a >> b;
            books.push_back(make_pair(a, b));
        }
        sort(books.begin(), books.end(), comp);
        for(int j=0; j<books.size(); j++){
            int a = books[j].first;
            int b = books[j].second;
            for(int i=a; i<=b; i++){
                if(v[i] == 0){
                    v[i] = 1;
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
