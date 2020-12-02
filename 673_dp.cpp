class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int,int>> dp(n + 1,{1,1});
        dp[0] = {0,1};
        std::pair<int,int> res({0,0});
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j < i; ++j){
                if(nums[j - 1] >= nums[i - 1]) continue;
                if(1 + dp[j].first > dp[i].first) dp[i] = {1 + dp[j].first, dp[j].second};
                else if(1 + dp[j].first == dp[i].first) dp[i].second += dp[j].second;
            }
            if(dp[i].first > res.first) res = dp[i];
            else if(dp[i].first == res.first) res.second += dp[i].second; 
        }
        return res.second;
    }
};
