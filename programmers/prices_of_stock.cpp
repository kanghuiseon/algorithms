#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size(); i++){
        answer.push_back(0);
    }
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++){
            if(prices[i] <= prices[j]){
                answer[i] += 1;
            }else{
                answer[i] += 1;
                break;
            }
            
        }
    }
    return answer;
}
