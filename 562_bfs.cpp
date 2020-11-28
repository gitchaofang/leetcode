class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int row = M.size();
        if(row == 0) return 0;
        int col = M[0].size();
        std::vector<std::pair<int,int>> dire({{1,-1},{1,0},{1,1},{0,1}});
        std::vector<std::vector<int>> dp(row * col, std::vector<int>(4,0));
        int res = 0;
        for(int i = row - 1; i >= 0; --i){
            for(int j = col - 1; j >= 0; --j){
                if(M[i][j] == 0) continue;
                int cnt = 1;
                for(int l = 0; l < 4; ++l){
                    dp[i * col + j][l] = 1;
                    std::pair<int,int>dir = dire[l];
                    int x = dir.first + i;
                    int y = dir.second + j;
                    if(x < 0 || x >= row || y < 0 || y >= col) continue;
                    dp[i * col + j][l] = std::max(dp[i * col + j][l], 1 + dp[x * col + y][l]);  
                    cnt = std::max(cnt, dp[i * col + j][l]);
                }
                res = std::max(cnt, res);
            }
        }
        return res;
    }
};
