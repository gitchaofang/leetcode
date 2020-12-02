class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row  = mat.size();
        int col = mat[0].size();
        std::vector<int> hit(col,0);
        int res = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                hit[j] = (mat[i][j] == 0) ? 0 : hit[j] + 1;
                int cnt = INT_MAX;
                for(int l = j; l >= 0; --l){
                    if(hit[l] == 0) break;
                    cnt = std::min(cnt, hit[l]);
                    res += cnt;
                }
            }
        }
        return res;
    }
};
