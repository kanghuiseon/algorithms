class Solution {
public:
    int matches = 0;
    void dfs(int n){
        if(n == 1)
            return;
        if(n % 2 == 0){
            matches += n/2;
            dfs(n/2);
        }
        else{
            matches += (n-1)/2;
            dfs((n-1)/2 + 1);
        }
    }
    
    int numberOfMatches(int n) {
        dfs(n);
        return matches;
    }
};
