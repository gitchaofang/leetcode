class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        std::vector<std::pair<int,int>> dire({{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,1},{-2,-1}});
        std::vector<double> dp(N*N ,1);
        for(int s = 0; s < K; ++s){
            std::vector<double> v = dp;
            for(int i = 0; i < N*N; ++i){
                dp[i] = 0; 
                for(const std::pair<int,int>& dir: dire){
                    int x = i / N + dir.first;
                    int y = i % N + dir.second;
                    if(x < 0 || x >= N || y < 0 || y >= N) continue;
                    dp[i] += v[x * N + y];  
                }
            }
        }
        return dp[r * N + c] / std::pow(8.0, K);
    }
};
