class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<int> sm(row * col, 0);
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        int sig = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] != 1) continue;
                --sig;
                int cnt = 0;
                std::queue<int> q({i * col + j});
                while(!q.empty()){
                    ++cnt;
                    for(int s = q.size(); s > 0; --s){
                        int cur = q.front();
                        q.pop();
                        for(const std::pair<int,int>& dir: dire){
                            int x = dir.first + cur / col;
                            int y = dir.second + cur % col;
                            if(x < 0|| x >= row || y < 0 || y >=col || grid[x][y]  != sig + 1) continue;
                            sm[x * col + y] += cnt;
                            grid[x][y] = sig;
                            q.push(x * col + y);
                        }
                    }
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < row * col; ++i){
            if(grid[i / col][i % col] != sig) continue;
            res = std::min(res, sm[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};
