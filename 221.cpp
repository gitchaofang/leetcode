class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        std::vector<std::vector<int>> dp(row + 1, std::vector<int>(col + 1, 0));
        int res = 0;
        for(int i = 1; i <= row; ++i){
            for(int j = 1; j <= col; ++j){
                if(matrix[i - 1][j - 1] == '0')continue;
                dp[i][j] = 1;
                int l = std::min(dp[i - 1][j], dp[i][j - 1]);
                if(l != 0){
                    if(matrix[i - l - 1][j - l - 1] == '1') dp[i][j] = l + 1;
                    else dp[i][j] = l;
                }
                res = std::max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
