class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<int> dp(col * col, 0);
        dp[col - 1] = (0 == col - 1) ? grid[0][0] : grid[0][0] + grid[0][col - 1];
        std::unordered_set<int>q({col - 1});
        std::vector<int> dire({-1,0,1});
        for(int i = 1; i < row; ++i){
            std::vector<int>v(col * col, 0);
            std::unordered_set<int> st;
            for(const int& cur: q){
                int rob1 = cur / col;
                int rob2 = cur % col;
                for(const int& dir1: dire){
                    for(const int& dir2: dire){
                        int x1 = rob1 + dir1;
                        int x2 = rob2  + dir2;
                        if(x1 < 0 || x2 < 0 || x1 >= col || x2 >= col) continue;
                        int d = dp[cur] + grid[i][x1] + grid[i][x2];
                        if(x1 == x2) d -= grid[i][x1];
                        st.insert(x1 * col + x2);
                        v[x1 * col + x2] = std::max(v[x1 * col + x2], d);
                    }
                }
            }
            dp = v;
            q = st;
        }
        int res = 0;
        for(const int& d: dp) res = std::max(res,d);
        return res;
    }
};
