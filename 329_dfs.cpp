class Solution {
public:
    int dfs(const std::vector<std::vector<int>>& matrix, const int& cur, std::vector<int>& record){
        int row = matrix.size();
        int col = matrix[0].size();
        if(record[cur] != -1) return record[cur];
        int res = 1;
        for(const std::pair<int,int>& dir: dire){
            int x = dir.first + cur / col;
            int y = dir.second + cur % col;
            if(x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] <= matrix[cur / col][cur % col]) continue;
            res = std::max(res, 1 + dfs(matrix, x * col + y, record));
        }
        record[cur] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        std::vector<int> record(row * col, -1);
        dire = {{0,-1},{-1,0},{0,1},{1,0}};
        int res = 1;
        for(int i = 0; i < row * col; ++i)res = std::max(res, dfs(matrix, i, record));
        return res;
    }
private:
    std::vector<std::pair<int,int>>dire;
};
