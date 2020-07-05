class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        std::unordered_map<int,std::vector<int>>m({{0,{0}}});
        std::vector<int> sum(n + 1, 0);
        std::vector<int> dp(n + 1, INT_MAX);
        for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + arr[i - 1];
        int res = INT_MAX;
        for(int i = 1; i <= n; ++i){
            int targ = sum[i] - target;
            dp[i] = dp[i - 1];
            if(m.find(targ) == m.end()){ 
                m[sum[i]].push_back(i);
                continue;
            }
            for(const int& pos: m[targ]){ 
                dp[i] = std::min(i - pos,dp[i]);
                if(dp[pos] != INT_MAX) res = std::min(res, i - pos + dp[pos]);
            }
            m[sum[i]].push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};
