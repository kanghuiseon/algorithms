#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool cmp(int& a, int& b){
    return a > b;
}
int main() {
    int n, m;
    scanf("%d", &n);
    vector<int> crane(n);
    for(int i=0; i<n; i++){
        cin >> crane[i];
    }
    scanf("%d", &m);
    vector<int> boxes(m);
    for(int i=0; i<m; i++){
        cin >> boxes[i];
    }
    int time = 0;
    sort(boxes.begin(), boxes.end(), cmp);
    sort(crane.begin(), crane.end(), cmp);
    if(crane[0] < boxes[0]){
        printf("-1\n");
        return 0;
    }
    while(true){
        time++;
        for(int i=0; i<n; i++){
            for(int j=0; j<boxes.size(); j++){
                if(crane[i] >= boxes[j]){
                    boxes.erase(boxes.begin()+j);
                    break;
                }
            }
        }
        if (boxes.size() == 0) {
            break;
        }
    }
    printf("%d\n", time);
    return 0;
}
