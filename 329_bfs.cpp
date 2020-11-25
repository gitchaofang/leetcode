class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        std::vector<int> dp(row * col, 1);
        std::queue<int> q;
        for(int i = 0; i < row * col; ++i) q.push(i);
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(const std::pair<int,int>& dir: dire){
                int x = cur / col + dir.first;
                int y = cur % col + dir.second;
                if(x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] <= matrix[cur / col][cur % col]) continue;
                int d = dp[cur] + 1;
                if(d <= dp[x * col + y]) continue;
                q.push(x * col + y);
                dp[x * col + y] = d;
            }
        }
        int res = 1;
        for(int i = 0; i < row * col; ++i) res = std::max(res, dp[i]);
        
        return res;
    }
};
