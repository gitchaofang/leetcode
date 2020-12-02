class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int row = pizza.size();
        int col = pizza[0].size();
        std::vector<std::vector<int>> sm(row , std::vector<int>(col,0));
        for(int i = row - 1; i >= 0; --i){
            int cnt = 0;
            for(int j = col - 1; j >= 0; --j){
                cnt += (pizza[i][j] == 'A');
                sm[i][j] = (i < row - 1) ? cnt + sm[i + 1][j] : cnt;
            }
        }
        
        int mod = std::pow(10, 9) + 7;
    
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(row * col, 0));
        for(int l = 1; l <= k; ++l){
            for(int pos = col * row - 1; pos >= 0; --pos){
                int i = pos / col;
                int j = pos % col;
                if(l == 1){
                    if(sm[i][j] > 0) dp[l][pos] = 1;
                    continue;
                }
                
                /*horizontal*/
                for(int x = i; x < row - 1; ++x){
                    if(sm[i][j] - sm[x + 1][j] > 0) dp[l][pos] = (dp[l][pos] + dp[l - 1][(x + 1) * col + j]) % mod;
                }
                
                for(int y = j; y < col - 1; ++y){
                    if(sm[i][j] - sm[i][y + 1] > 0) dp[l][pos] = (dp[l][pos] + dp[l - 1][i * col + y + 1]) % mod;
                }
            }
        }
        return dp[k][0];
    }
};
