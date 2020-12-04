class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        if(n == 1) return 1;
        std::queue<int> q({0});
        int cnt = 1;
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}});
        while(!q.empty()){
            ++cnt;
            for(int i = q.size(); i > 0; --i){
                int cur = q.front();
                q.pop();
                for(const std::pair<int,int>& dir: dire){
                    int x = dir.first + cur / n;
                    int y = dir.second + cur % n;
                    if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1) continue;
                    if(x == n - 1 && y == n - 1) return cnt;
                    grid[x][y] = 1;
                    q.push(x * n + y);
                }
            }
        }
        return -1;
    }
};
