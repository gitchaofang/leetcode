class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<int>> sm(row + 1, std::vector<int>(col + 1, 0));
        for(int i = 1; i <= row; ++i){
            int cnt = 0;
            for(int j = 1; j <= col; ++j){
                cnt += matrix[i - 1][j - 1];
                sm[i][j] = cnt + sm[i - 1][j];
            }
        }
        
        int res = 0;
        for(int i = 1; i <= row; ++i){
            for(int l = 0; l < i; ++l){
                std::unordered_map<int,int>m({{0,1}});
                for(int j = 1; j <= col; ++j){
                    int d = sm[i][j] - sm[l][j];
                    res += m[d - target];
                    ++m[d];
                }
            }
        }
        return res;
    }
};
