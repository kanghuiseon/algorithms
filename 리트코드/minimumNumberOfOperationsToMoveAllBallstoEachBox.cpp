class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> indexs;
        vector<int> result;
        for(int i=0; i<boxes.size(); i++){
            if(boxes[i] == '1')
                indexs.push_back(i);
        }
        for(int i=0; i<boxes.size();i++){
            int cnt=0;
            for(int j=0; j<indexs.size(); j++){
                cnt += abs(i-indexs[j]);
            }
            result.push_back(cnt);
        }
        return result;
    }
};
