class Solution {
public:
    int dfs(const std::vector<std::vector<int>>& grid, const int& cur){
        int res = 0;
        visited[cur] = true;
        for(const std::pair<int,int>& dir: dire){
            int x = cur / col + dir.first;
            int y = cur % col + dir.second;
            if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0 || visited[x * col + y] == true) continue;
            res = std::max(res, dfs(grid,x * col + y));
        }
        res += grid[cur / col][cur % col];
        visited[cur] = false;
        return res;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        visited.resize(row * col, false);
        dire = {{0,-1},{-1,0},{0,1},{1,0}};
        int res = 0;
        for(int i = 0; i < row * col; ++i){
            if(grid[i / col][i % col] == 0) continue;
            res = std::max(res, dfs(grid,i));
        }
        return res;
    }
private:
    std::vector<bool> visited;
    int row;
    int col;
    std::vector<std::pair<int,int>> dire;
};
