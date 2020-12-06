lass Solution {
public:
    bool dfs(const std::vector<std::vector<char>>& board, const int& cur, const std::string& targ, const int& pos){
        if(board[cur / col][cur % col] != targ[pos]) return false;
        if(pos == targ.size() - 1) return true;
        visited[cur] = true;
        for(const std::pair<int,int>& dir: dire){
            int x = dir.first + cur / col;
            int y = dir.second + cur % col;
            if(x < 0 || x >= row || y < 0  || y >= col || visited[x * col + y] == true) continue;
            if(dfs(board, x * col + y, targ, pos + 1)) return true;
        }
        visited[cur] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        visited.resize(row * col, false);
        dire = {{0,-1},{-1,0},{0,1},{1,0}};
        for(int i = 0; i < row * col; ++i){
            if(dfs(board,i,word,0)) return true;
        }
        return false;
    }
private:
    std::vector<bool>visited;
    std::vector<std::pair<int,int>> dire;
    int row;
    int col;
};
