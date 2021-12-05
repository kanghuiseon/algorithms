class Solution {
public:
    vector<int> check;
    vector<vector<int>> arr;
    bool checkCycle(int node){
        check[node] = 2;
        for(int i=0; i<arr[node].size(); i++){
            if(check[arr[node][i]] == 2){
                return true;
            }else if(check[arr[node][i]] == 0 && checkCycle(arr[node][i])){
                return true;
            }
        }
        check[node] = 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        check.resize(numCourses, 0);
        arr.resize(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            arr[a].push_back(b);
        }
        for(int i=0; i<numCourses; i++){
            if(check[i] == 0 && checkCycle(i)){
                return false;
            }
        }
        return true;
    }
};
