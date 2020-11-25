class Solution {
public:
    int dfs(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& dp, const int& i, const int& j){
        int res = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        for(const std::pair<int,int>& dir: dire){
            int x = i + dir.first;
            int y = j + dir.second;
            if(x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] <= matrix[i][j]) continue;
            if(dp[x][y] != -1) res = std::max(dp[x][y], res);
            else res = std::max(res,dfs(matrix,dp,x,y));
        }
        dp[i][j] = res + 1;
        return res + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        std::vector<std::vector<int>> dp(row,  std::vector<int>(col,-1));
        int res = 0;
        dire = {{0,-1},{-1,0},{1,0},{0,1}};
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(dp[i][j] != -1) res = std::max(dp[i][j],res);
                else res = std::max(res,dfs(matrix, dp, i,j));
            }
        }
        return res;
    }
private:
    std::vector<std::pair<int,int>> dire;
};
