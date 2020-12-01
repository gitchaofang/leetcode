class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        std::vector<std::vector<int>>dp(n + 1, std::vector<int>(n + 1, n + 1));
        dp[0][0] = 0;
        for(int l = 1; l <= n; ++l){
            for(int i = 1; i <= n; ++i){
                if(l == 1) {
                    dp[i][i] = 0;
                    continue;
                }
                if(i + l - 1 > n) break;
                int j = i + l - 1;
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i + 1][j]);
                if(s[i - 1] == s[j - 1]) {
                    dp[i][j] = std::min(dp[i][j], (i + 1 == j) ? 0 :dp[i + 1][j - 1]);
                }
            }
        }
        return dp[1][n];
    }
};
