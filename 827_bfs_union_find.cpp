class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<int> root(row * col, 0);
        std::vector<int> land_size(row * col, 1);
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
         int res = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] != 1) continue;
                grid[i][j] = -1;
                std::queue<int> q({i * col + j});
                int cnt = 0;
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    ++cnt;
                    root[cur] = i * col + j;
                    for(const std::pair<int,int>& dir: dire){
                        int x = dir.first + cur / col;
                        int y = dir.second + cur % col;
                        if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] != 1) continue;
                        grid[x][y] = -1;
                        q.push(x * col + y);
                    }
                }
                res = std::max(res,cnt);
                land_size[i * col + j] = cnt;
            }
        }
        
       
        for(int i = 0; i < row * col; ++i){
            if(grid[i / col][i % col] != 0) continue;
            std::unordered_set<int> nb_root;
            for(const std::pair<int,int>& dir: dire){
                int x = dir.first + i / col;
                int y = dir.second + i % col;
                if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] != -1) continue;
                nb_root.insert(root[x*col + y]);
            }
            int cnt = 0;
            for(const int& nb: nb_root) cnt += land_size[root[nb]];
            res = std::max(cnt + 1, res);
        }
        return res;
        
        
        
    }
};
