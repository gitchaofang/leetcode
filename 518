class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<std::vector<int>> dp(coins.size() + 1, std::vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= coins.size(); ++i){
            dp[i][0] = 1;
            for(int j = 1; j <= amount; ++j){
                dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
            }
        }
        return dp[coins.size()][amount];        
    }
};
