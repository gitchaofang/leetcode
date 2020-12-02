class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n + 1, 1);
        dp[0] = 0;
        int res = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = i - 1; j >= 1; --j){
                if(nums[i - 1] > nums[j - 1]) dp[i] = std::max(dp[i], dp[j] + 1);
            }
            res = std::max(dp[i],res);
        }
        return res;
    }
};
