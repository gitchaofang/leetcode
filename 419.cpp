class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return 0;
        int col = board[0].size();
        int cnt = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == '.') continue;
                ++cnt;
                board[i][j] = '.';
                int l = j + 1;
                while(l < col && board[i][l] == 'X'){
                    board[i][l] = '.';
                    ++l;
                }
                l = i + 1;
                while(l < row && board[l][j] == 'X'){ 
                    board[l][j] = '.';
                    ++l;
                }
            }
        }
        return cnt;
    }
};
