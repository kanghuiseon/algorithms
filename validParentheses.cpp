class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            char par = s[i];
            if(par=='(' || par=='{' || par=='['){
                st.push(par);
                continue;
            }
            if(st.empty())
                return false;
            if((par==')' && st.top()!='(') || (par=='}' && st.top()!='{') || (par==']' && st.top()!='[')){
                return false;
            }
            st.pop();
        }
        if(st.empty())
            return true;
        return false;
    }
};
