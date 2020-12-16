class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        std::vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        std::vector<int> dire({1,2});
        for(int i = n - 1; i >= 0; --i){
            for(const int& dir: dire){
                int next = i + dir;
                if(next > n || dp[next] == INT_MAX) continue;
                dp[i] = std::min(dp[i], dp[next]);
            }
            if(dp[i] != INT_MAX) dp[i] += cost[i];
        }
        int res = std::min(dp[0],dp[1]);
        return res == INT_MAX ? -1 : res;
    }
};
