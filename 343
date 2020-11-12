lass Solution {
public:
    int integerBreak(int n) {
        std::vector<int> dp(n + 1, -1);
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j < i; ++j){ 
                dp[i] = std::max(dp[i], (i - j) * j);
                dp[i] = std::max(dp[i], j * dp[i - j]);
                dp[i] = std::max(dp[i], dp[j] * (i - j));
                dp[i] = std::max(dp[j] * dp[i - j], dp[i]);
            }
        }
        return dp[n];
    }
};
