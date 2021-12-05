#include <queue>
#include <cstring>
class Solution {
public:
    vector<int> check;
    vector<vector<int>> arr;
    bool checkCycle(int node){
        // 0 : 아직 한번도 방문 안한것, 1 : 한번 방문한 적이 있던것, 2 : 방문한것
        // 연결된 노드의 체크 값이 2이면 사이클이 존재한다는 의미
        check[node] = 2;
        for(int i=0; i<arr[node].size(); i++){
            int neighbor = arr[node][i];
            if(check[neighbor] == 2){ // 사이클이 존재하는 경우
                return true;
            }else if(check[neighbor] == 0 && checkCycle(neighbor)){ // 한번도 방문 안했지만 사이클이 존재하는 경우
                return true;
            }
        }
        // 1로 설정해줘야 함
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
