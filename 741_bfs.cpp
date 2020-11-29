class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<std::vector<int>> dp(row * col, std::vector<int>(row * col, 0));
        std::queue<std::pair<int,int>>q({{0,0}});
        dp[0][0] += grid[0][0];
        std::vector<std::pair<int,int>> dire({{0,1},{1,0}});
        while(!q.empty()){
            std::pair<int,int> cur = q.front();
            q.pop();
            for(const std::pair<int,int>& dir1: dire){
                for(const std::pair<int,int>& dir2: dire){
                    int x1 = dir1.first + cur.first / col;
                    int y1 = dir1.second + cur.first % col;
                    int x2 = dir2.first + cur.second / col;
                    int y2 = dir2.second + cur.second % col;
                    if(x1 < 0 || x1 >= row || y1 < 0 || y1 >= col || x2 < 0 || x2 >= row || y2 < 0 || y2 >= col || grid[x1][y1] == -1 || grid[x2][y2] == -1) continue;
                    int d = dp[cur.first][cur.second] + grid[x1][y1] + grid[x2][y2];
                    if(x1 * col + y1 == x2 * col + y2) d -= grid[x1][y1];
                    if(d <= dp[x1 * col + y1][x2 * col + y2]) continue;
                    dp[x1 * col + y1][x2 * col + y2] = d;
                    q.push({x1 * col + y1, x2 * col + y2});
                }
            }
        }
        return dp[row * col - 1][row * col - 1];
    }
};
