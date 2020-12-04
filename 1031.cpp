class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        /*first L, second M*/
        std::vector<std::pair<int,int>> dp(n + 1, {0,0});
        std::vector<int> sm(n + 1, 0);
        int res = 0;
        for(int i = 1; i <= n; ++i){ 
            sm[i] = sm[i - 1] + A[i - 1];
            if(i < L && i < M) continue;
            if(i >= L) dp[i].first = std::max(sm[i] - sm[i - L], dp[i - 1].first);
            if(i >= M) dp[i].second = std::max(sm[i] - sm[i - M], dp[i - 1].second);
            /*L M*/
            if(i >= L+ M){ 
                res = std::max(res, std::max(sm[i] - sm[i - L] + dp[i - L].second, sm[i] - sm[i - M] + dp[i - M].first));
            }
        }
        return res;
    }
};
