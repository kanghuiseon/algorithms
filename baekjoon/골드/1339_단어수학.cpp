#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// (int)'a'-97
vector<int> alphas(26);
bool cmp(int& a, int& b){
    return a > b;
}
int main() {
    int n;
    cin >> n;
    vector<string> words;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<words[i].size(); j++){
            int tmp = 1;
            for(int k=0; k<words[i].size()-j-1; k++){
                tmp = tmp*10;
            }
            char c = tolower(words[i][j]);
            alphas[(int)c-97] += tmp;
        }
    }
    int num = 9;
    int answer = 0;
    sort(alphas.begin(), alphas.end(), cmp);
    for(int i=0; i<26; i++){
        if(alphas[i] != 0){
            answer += num * alphas[i];
            num--;
        }
    }
    printf("%d\n", answer);
    return 0;
}
