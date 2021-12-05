#include <queue>
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> arr(numCourses);
        queue<int> q;
        for(int i=0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            arr[a].push_back(b);
        }
        // a를 듣기 위해선 b를 우선 들어야 한다.
        // 그럼 화살표가 b->a 이므로 이것에 맞게
        // incoming edge의 수를 세준다.
        for(int i=0; i<prerequisites.size(); i++){
            indegree[prerequisites[i][1]]++;
        }
        
        for(int i=0; i<numCourses; i++){
            // incoming edge가 없는 경우
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // 결국 모든 노드를 다 보는게 됨. 근데 전체 노드의 개수보다 큰 값이 나온다면 사이클이 존재한다는 의미.
            cnt++;
            for(int i=0; i<arr[node].size(); i++){
                // edge제거하기, 제거해서 0이되면 incoming edge가 없다는 의미니까 큐에 넣어준다.
                indegree[arr[node][i]]--;
                if(indegree[arr[node][i]] == 0){
                    q.push(arr[node][i]);
                }
            }
        }
        // 같으면 노사이클, 다르면 예스사이클
        return cnt == numCourses;
    }
};
