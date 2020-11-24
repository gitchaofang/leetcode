class Solution {
public:
    bool dc(const std::vector<std::vector<int>>& matrix, const std::pair<int,int>& row, const std::pair<int,int>& col, const int& targ){
        if(row.first > row.second || col.first > col.second) return false;
        int mid = col.first + (col.second - col.first) / 2;
        for(int i = row.first; i <= row.second; ++i){
            if(matrix[i][mid] == targ) return true;
            if(i > row.first && targ > matrix[i - 1][mid] && targ < matrix[i][mid]){
                return dc(matrix, {i, row.second},{col.first, mid - 1},targ) || dc(matrix, {row.first, i - 1},{mid + 1, col.second}, targ);
            }
            if(i == row.first && matrix[i][mid] > targ){
                return dc(matrix, row, {col.first, mid - 1}, targ);
            }
            else if(i == row.second && targ > matrix[i][mid]){
                return dc(matrix, row, {mid  + 1, col.second}, targ);
            } 
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        return dc(matrix, {0, matrix.size() - 1}, {0, matrix[0].size() - 1}, target);
    }
};
