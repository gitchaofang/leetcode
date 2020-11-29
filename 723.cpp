class Solution {
public:
    void drop(std::vector<std::vector<int>>& v, const std::unordered_set<int>& delete_set){
        int row = v.size();
        for(const int& j : delete_set){
            int pos = row - 1;
            for(int i = row - 1; i >= 0; --i){
                if(v[i][j] != 0) std::swap(v[pos--][j], v[i][j]);
            }
        }
        return;
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        bool change = true;
        while(change){
            change = false;
            std::stack<int> st;
            for(int i = 0; i < row; ++i){
                for(int j = 0; j < col; ++j){
                    if(board[i][j] == 0) continue;
                    int c = board[i][j];
                    /*check if can delete*/
                    int top = i;
                    int bottom = i;
                    while(top >=0 && board[top][j] == c) --top;
                    while(bottom < row && board[bottom][j] == c) ++bottom;
                    if(bottom - top - 1 >= 3) st.push(i * col + j);
                    else{
                        top = j;
                        bottom = j;
                        while(top >=0 && board[i][top] == c) --top;
                        while(bottom < col && board[i][bottom] == c) ++bottom;
                        if(bottom - top - 1 >= 3) st.push(i * col + j);
                    }
                }
            }
            if(!st.empty()) change = true;
            std::unordered_set<int> delete_set;
            while(!st.empty()){
                board[st.top() / col][st.top() % col] = 0;
                delete_set.insert(st.top() % col);
                st.pop();
            }
            drop(board, delete_set);
        }
        return board;
    }
};
