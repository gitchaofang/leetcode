class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        int res = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 0) continue;
                int cnt = 0;
                for(const std::pair<int,int>& dir: dire){
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0) ++cnt; 
                }
                res += cnt;
            }
        }
        return res;
    }
};
