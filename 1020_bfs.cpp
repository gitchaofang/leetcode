class Solution {
public:
    void remove(std::vector<std::vector<int>>& A, const int& cur){
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        int row = A.size();
        int col = A[0].size();
        std::queue<int>q({cur});
        A[cur / col][cur % col] = 0;
        while(!q.empty()){
            int d = q.front();
            q.pop();
            for(const std::pair<int,int>& dir: dire){
                int x = dir.first + d / col;
                int y = dir.second + d % col;
                if(x < 0 || x >= row || y < 0 || y >= col || A[x][y] == 0) continue;
                A[x][y] = 0;
                q.push(x * col + y);
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        for(int i = 0; i < col; ++i){
            if(A[0][i] != 0) remove(A, i);
            if(A[row - 1][i] != 0) remove(A, (row - 1) * col + i);
        }
        for(int i = 0; i< row; ++i){
            if(A[i][0] != 0) remove(A, i*col);
            if(A[i][col - 1] != 0) remove(A, i * col + col - 1);
        }
        int res = 0;
        for(int i = 0; i < row * col; ++i) res += A[i / col][i % col];
        return res;
    }
};
