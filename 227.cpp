class Solution {
public:
    int calculate(string s) {
        std::stack<int> st;
        char sign = '+';
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' ') continue;
            if(s[i] <= '9' && s[i] >= '0'){
                int j = i;
                int num = 0;
                while(i < s.size() && s[j] <= '9' && s[j] >= '0') num = num * 10 + (s[j++] - '0');
                i = j - 1;
                if(sign == '+') st.push(num);
                else if(sign == '-') st.push(-1 * num);
                else if(sign == '*'){
                    num *= st.top();
                    st.pop();
                    st.push(num);
                }
                else if(sign == '/'){
                    num = st.top()/ num;
                    st.pop();
                    st.push(num);
                }
            }
            else sign = s[i];
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};
