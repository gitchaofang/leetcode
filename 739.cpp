iclass Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        std::vector<int> res(n);
        std::stack<int>st;
        for(int i = 0; i < T.size(); ++i){
            while(!st.empty() && T[st.top()] < T[i]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            res[st.top()] = 0;
            st.pop();
        }
        return res;
    }
};
