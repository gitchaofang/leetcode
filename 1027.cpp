class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(1001,1));
        int res = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i - 1; ++j){
                int d = A[i - 1] - A[j - 1] + 500;
                dp[i][d] = std::max(dp[i][d], dp[j][d] + 1);
                res = std::max(dp[i][d], res);
            }
        }
        return res;
    }
};
