class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        row = m + 1;
        col = n + 1;
        sm.resize((m + 1) * (n + 1),0);
        for(int i = 1; i <= m; ++i){
            int cnt = 0;
            for(int j = 1; j <= n; ++j){
                cnt += matrix[i - 1][j - 1];
                sm[i * col + j] = sm[(i - 1) * col + j] + cnt;
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sm[(row2 + 1) * col + col2 + 1] - sm[row1 * col + col2 + 1] - sm[(row2 + 1) * col + col1] + sm[row1 * col + col1];    
    }
private:
    std::vector<int> sm;
    int row;
    int col;
};
