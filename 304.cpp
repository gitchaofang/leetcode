class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();
        sum.resize(row);
        for(int i = 0; i < row; ++i){
            int sm = 0;
            sum[i].push_back(0);
            for(int j = 0; j < col; ++j){
                sm += matrix[i][j];
                sum[i].push_back(sm);
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sm = 0;
        for(int i = row1; i <= row2; ++i){
            sm += sum[i][col2 + 1] - sum[i][col1];
        }
        return sm;
    }
private:
    std::vector<std::vector<int>> sum;
};

