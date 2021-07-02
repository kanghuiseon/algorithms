#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n, k;
    string number;
    cin >> n >> k;
    cin >> number;
    stack<char> st;
//    int =1;
//    st.push(number[0]);
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top() < number[i] && k>0){
            st.pop();
            --k;
        }
        st.push(number[i]);
    }
    if(k){
        while(k){
            st.pop();
            --k;
        }
    }
    stack<char> tmp;
    while(!st.empty()){
        tmp.push(st.top());
        st.pop();
    }
    while(!tmp.empty()){
        cout<<tmp.top();
        tmp.pop();
    }
    return 0;
}
