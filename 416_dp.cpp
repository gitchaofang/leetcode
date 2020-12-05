class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sm = std::accumulate(nums.begin(), nums.end(),0);
        if(sm % 2 != 0) return false;
        sm /= 2;
        int n = nums.size();
        std::vector<bool> dp(sm + 1, false);
        dp[0] = true;
        for(int i = 0; i < n; ++i){
            for(int j = sm; j >= 1; --j){
                if(j < nums[i]) continue;
                if(dp[j - nums[i]] == true) dp[j] = true;
            }
        }
        return dp[sm];
    }
};
