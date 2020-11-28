class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        for(int i = 0; i < row * col; ++i){
            if(grid[i / col][i % col] == 0) continue;
            int cnt = 0;
            std::queue<int>q({i});
            grid[i / col][i % col] = 0;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                ++cnt;
                for(const std::pair<int,int>& dir: dire){
                    int x = cur / col + dir.first;
                    int y = cur % col + dir.second;
                    if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0) continue;
                    q.push(x * col + y);
                    grid[x][y] = 0;
                }
            }
            res = std::max(res, cnt);
        }
        return res;
    }
};
