#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;
struct File{
    string HEAD, ORIGNAL_NAME;
    int NUM;
};
bool compare(const File& a, const File& b){
    if(a.HEAD != b.HEAD){
        return a.HEAD < b.HEAD;
    }
    else
        return a.NUM < b.NUM;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> Files(files.size());
    for(int i=0; i<files.size(); i++){
        string tmp = "";
        Files[i].ORIGNAL_NAME = files[i];
        int j;
        for(j=0; j<files[i].size(); j++){
            if(!isdigit(files[i][j])){
                tmp += files[i][j];
            }else{
                for(int l=0; l<tmp.size(); l++){
                    tmp[l] = tolower(tmp[l]);
                }
                Files[i].HEAD = tmp;
                tmp = "";
                break;
            }
        }
        for(int k=j; k<files.size()+1; k++){
            if(isdigit(files[i][k])){
                tmp += files[i][k];
            }
            else if(files[i][k] == '.' || files[i][k] == '\0' || files[i][k] == '-' || isalpha(files[i][k]) || files[i][k] == ' '){
                Files[i].NUM = stoi(tmp);
                break;
            }
        }
    }
    stable_sort(Files.begin(), Files.end(), compare);
    for(int i=0; i<Files.size(); i++){
        answer.push_back(Files[i].ORIGNAL_NAME);
    }
    return answer;
}
