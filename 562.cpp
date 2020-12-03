class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int row = M.size();
        if(row == 0) return 0;
        int col = M[0].size();
        std::vector<std::vector<int>> line(col,{0,0,0});
        std::vector<int> dire({-1,0,1});
        int res = 0;
        for(int i = row - 1; i >= 0; --i){
            std::vector<std::vector<int>> new_line(col,{0,0,0});
            int cnt = 0;
            for(int j = col - 1; j >= 0; --j){
                if(M[i][j] == 0) cnt = 0;
                else{
                    ++cnt;
                    for(int l = 0; l < 3; ++l){
                        new_line[j][l] = 1;
                        int dir = dire[l];
                        int nb = dir + j;
                        if(nb < 0 || nb >= col) continue;
                        new_line[j][l] = std::max(new_line[j][l], 1 + line[nb][l]);
                        res = std::max(std::max(res, new_line[j][l]), cnt);
                    }
                }
            }
            line = new_line;
        }
        return res;
    }
};
