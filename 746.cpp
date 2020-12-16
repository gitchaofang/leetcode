class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        std::vector<int> dp(n + 1,INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        std::queue<int> q({0,1});
        std::vector<int> step({1,2});
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(const int& s: step){
                int next = cur + s;
                if(next > n) continue;
                int c = cost[cur] + dp[cur];
                if(dp[next] <= c) continue;
                dp[next] = c;
                q.push(next);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
