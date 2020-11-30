class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::unordered_set<int> visited;
        std::stack<int> st;
        int pos = 0;
        for(int i = 0; i < pushed.size(); ++i){
            st.push(pushed[i]);
            visited.insert(pushed[i]);
            while(!st.empty() && st.top() == popped[pos]){ 
                ++pos;
                visited.erase(st.top());
                st.pop();
            }
            if(!st.empty() && visited.find(popped[pos]) != visited.end()) return false;
        }
        return st.empty();
    }
};
