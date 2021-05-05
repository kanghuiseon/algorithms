#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    // 1
    for(int i=0; i<new_id.size(); i++){
        new_id[i] = tolower(new_id[i]);
    }
    // 2
    for(int i=0; i<new_id.size();){
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || islower(new_id[i]) || (new_id[i] >= '0' && new_id[i] <='9')){
            i++;
            continue;
        }
        new_id.erase(new_id.begin()+i);
    }
    // 3
    for(int i=0; i<new_id.size();){
        if(new_id[i] == '.' && new_id[i+1] == '.'){
            new_id.erase(new_id.begin()+i);
            continue;
        }
        i++;
    }
    
    // 4
    if(new_id.front() == '.')
        new_id.erase(new_id.begin());
    if(new_id.back() == '.')
        new_id.erase(new_id.end()-1);
    
    // 5
    if(new_id.empty())
        new_id += "a";
    
    //6
    if(new_id.size() >= 16){
        while(new_id.size() != 15){
            new_id.erase(new_id.begin()+15);
        }
    }
    if(new_id.back() == '.')
        new_id.erase(new_id.end()-1);
    if(new_id.size() <= 2){
        while(new_id.size() <= 2){
            new_id += new_id[new_id.size()-1];
        }
    }
    return new_id;
}
