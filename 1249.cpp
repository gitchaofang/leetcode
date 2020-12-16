class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != '(' && s[i] != ')') continue;
            if(s[i] == '(') st.push(i);
            else if(st.empty()){
                s.erase(s.begin() + i);
                --i;
            }
            else st.pop();
        }
        while(!st.empty()){
            s.erase(s.begin() + st.top());
            st.pop();
        }
        return s;
    }
};
