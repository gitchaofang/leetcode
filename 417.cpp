class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return {};
        int col = matrix[0].size();
        std::vector<int> dp(row * col, 0);
        std::queue<std::pair<int,int>>q;
        std::vector<std::vector<int>>res;
        for(int i = 0; i < row * col; ++i){
            if(i / col == 0 || i % col == 0){ 
                dp[i] += 1;
                q.push({i,1});
            }
            if(i / col == row - 1 || i % col == col - 1){ 
                dp[i] += 2;
                q.push({i,2});
            }
            if(dp[i] == 3) res.push_back({i / col, i % col});
        }
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        while(!q.empty()){
            std::pair<int,int> p = q.front();
            q.pop();
            for(const std::pair<int,int>& dir: dire){
                int x = dir.first + p.first / col;
                int y = dir.second + p.first % col;
                if(x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] < matrix[p.first / col][p.first % col] ||dp[x * col + y] == 3 || dp[x * col + y] == p.second) continue;
                dp[x * col + y] += p.second;
                q.push({x * col + y, p.second});
                if(dp[x * col + y] == 3) res.push_back({x,y});
            }
        }
        return res;
    }
};
