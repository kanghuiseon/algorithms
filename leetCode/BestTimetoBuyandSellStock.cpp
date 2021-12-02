class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int answer = 0;
        int Max = prices[n-1];
        for(int i=n-2; i>=0; i--){
            if(Max < prices[i]){
                Max = prices[i];
            }else if(Max > prices[i]){
                answer = max(Max-prices[i], answer);
            }
        }
        return answer;
    }
};
