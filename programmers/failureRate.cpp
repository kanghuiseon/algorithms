#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
bool comp(pair<float, int>& a, pair<float, int>& b){
    if(a.first>b.first)
        return true;
    else if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> arr(N+1, 0);
    vector<pair<float, int> > p;
    for(int i=0; i<stages.size(); i++){
        arr[stages[i]-1] += 1;
    }
    int sizee = stages.size();
    for(int i=0; i<arr.size()-1; i++){
        p.push_back(make_pair(float(arr[i])/float(sizee), i+1));
        sizee -= arr[i];
        if(sizee <= 0)
            break;
    }
    if(p.size() != N){
        int num = p.size();
        for(int i = num+1; i<=N; i++)
            p.push_back(make_pair(float(0), i));
    }
    sort(p.begin(), p.end(), comp);
    for(int i=0; i<p.size(); i++){
        answer.push_back(p[i].second);
    }
    return answer;
}
