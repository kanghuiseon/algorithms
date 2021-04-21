#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> tick;
vector<string> answer;
vector<bool> check = {false,};
int n;
string min_string = "a";
void dfs(string current, int cnt, string total){
    if(cnt == n){
        if(total < min_string){
            min_string = total;
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(current == tick[i][0] && !check[i]){
            check[i] = true;
            dfs(tick[i][1], cnt+1, total + tick[i][1]);
            check[i] = false;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    tick = tickets;
    n = tickets.size();
    dfs("ICN", 0, "ICN");
    for(int i=0; i<min_string.size(); i+=3){
        answer.push_back(min_string.substr(i,3));
    }
    return answer;
}
