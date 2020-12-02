class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int row = mat.size();
        int col = mat[0].size();
        std::vector<std::vector<int>> sm(row + 1, std::vector<int>(col + 1, 0));
        for(int i = 1; i <= row; ++i){
            int cnt =  0;
            for(int j = 1; j <= col; ++j){
                cnt += mat[i - 1][j - 1];
                sm[i][j] = sm[i - 1][j] + cnt;
            }
        }
        
        for(int i = 1; i <= row; ++i){
            for(int j = 1; j <= col; ++j){
                std::pair<int,int> up = {std::max(1, i - K), std::max(1, j - K)};
                std::pair<int,int> down = {std::min(row, i + K), std::min(col, j + K)};
                mat[i - 1][j - 1] = sm[down.first][down.second] - sm[up.first - 1][down.second] - sm[down.first][up.second - 1] + sm[up.first - 1][up.second - 1];
            }
        }
        return mat;
    }
};
