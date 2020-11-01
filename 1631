class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        std::vector<std::vector<int>> dp(row, std::vector<int>(col,INT_MAX));
        dp.back().back() = 0;
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        std::queue<std::pair<int,int>>q({{row - 1, col - 1}});
        while(!q.empty()){
            std::pair<int,int>p = q.front();
            q.pop();
            int gp = dp[p.first][p.second];
            for(const std::pair<int,int>& dir: dire){
                int x = p.first + dir.first;
                int y = p.second + dir.second;
                if(x < 0 || x >= row || y < 0 || y >= col) continue;
                int d = std::max(gp,std::abs(heights[p.first][p.second] - heights[x][y]));
                if(dp[x][y] > d){
                    q.push({x,y});
                    dp[x][y] = d;
                }
            }
        }
        return dp[0][0];
    }
};
