class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        std::vector<int> dp(n + 1, 0);
        std::stack<std::pair<int,int>> st;
        st.push({-1,0});
        int res = 0;
        int mod = std::pow(10,9) + 7;
        for(int i = 1; i <= n; ++i){
            while(st.top().first >= arr[i - 1]) st.pop();
            int d = (arr[i - 1] * (i - st.top().second) % mod + dp[st.top().second]) % mod;
            st.push({arr[i - 1],i});
            dp[i] = d;
            res = (res + d) % mod;
        }
        return res;
    }
};
