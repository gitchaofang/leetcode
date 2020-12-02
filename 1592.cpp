class Solution {
public:
    string reorderSpaces(string text) {
        std::stack<std::string> st;
        int cnt = 0;
        for(int i = 0; i < text.size(); ++i){
            if(text[i] == ' ') ++cnt; 
            else{
                int j = i; 
                while(j < text.size() && text[j] != ' ') ++j;
                st.push(text.substr(i, j - i));
                i = j - 1;
            }
        }
        int space_num = (st.size() == 1) ? 0 : cnt / (st.size() - 1);
        int tail = (st.size() == 1) ? cnt : cnt % (st.size() - 1);
        std::string res = st.top();
        st.pop();
        while(!st.empty()){
            res = st.top() + std::string(space_num, ' ') + res;
            st.pop();
        }
        if(tail != 0) res += std::string(tail,' ');
        return res;
    }
};
