class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int row = A.size();
        int col = B[0].size();
        std::vector<std::unordered_set<int>> ma(row);
        std::vector<std::unordered_set<int>> mb(col);
        std::vector<std::vector<int>> res(row, std::vector<int>(col,0));
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < A[i].size(); ++j){
                if(A[i][j] != 0) ma[i].insert(j);
            }
        }
        for(int i = 0; i < B.size(); ++i){
            for(int j = 0; j < col; ++j){
                if(B[i][j] != 0) mb[j].insert(i);
            }
        }
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                int cnt = 0;
                for(const int& d: ma[i]){
                    if(mb[j].find(d) != mb[j].end()) cnt += A[i][d] * B[d][j];
                }
                res[i][j] = cnt;
            }
        }
        return res;
    }
};
