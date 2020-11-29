class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::stack<int> st;
        std::stack<int> res;
        for(int i = T.size() - 1; i >= 0; --i){
            while(!st.empty() && T[st.top()] <= T[i]) st.pop();
            if(st.empty()) res.push(0);
            else res.push(st.top() - i);
            st.push(i);
        }
        std::vector<int> v;
        while(!res.empty()){
            v.push_back(res.top());
            res.pop();
        }
        return v;
    }
};
