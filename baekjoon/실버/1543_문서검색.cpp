#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
string doc;
string word;
int Max = -1;
int check(int idx){
    int cnt=0;
    int index = 0;
    for(int i=idx; i<doc.size(); i++){
        if(doc[i]==word[index]){
            index++;
        }
        else{
            index=0;
        }
        if(index == word.size()){
            cnt++;
            index=0;
        }
    }
    return cnt;
}
int main(){
    getline(cin, doc);
    getline(cin, word);
    if(doc.size() < word.size()){
        cout<< "0" <<endl;
        return 0;
    }
    int size = doc.size();
    for(int i=0; i<size; i++){
        if(doc[i] == word[0]){
            int ans = check(i);
            Max = max(ans, Max);
        }
    }
    cout << Max << endl;
    return 0;
}
