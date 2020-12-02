class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int row = A.size();
        int n = A[0].size();
        std::vector<int>dp(n + 1, 1);
        dp[0] = 0;
        int res = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i - 1; j >= 1; --j){
                bool sucess = true;
                for(int l = 0; l < row; ++l){
                    if(A[l][i - 1] >= A[l][j - 1]) continue;
                    sucess = false;
                    break;
                }
                if(sucess == true) dp[i] = std::max(dp[i], 1 + dp[j]);
            }
            res = std::max(dp[i],res);
        }
        return n - res;
    }
};
