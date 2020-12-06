class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        std::vector<int> high(col,0);
        int res = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(matrix[i][j] == '0'){ 
                    high[j] = 0;
                    continue;
                }
                ++high[j];
                int cnt = INT_MAX;
                int l = j;
                while(l >= 0 && high[l] != 0){
                    cnt = std::min(cnt, high[l]);
                    res = std::max(res, (j - l + 1) * cnt);
                    --l;
                }
            }
        }
        return res;
    }
};
