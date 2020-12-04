class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        std::vector<int> lm(n + 1, 0);
        std::vector<int> mm(n + 1, 0);
        std::vector<int> sm(n + 1, 0);
        int res = 0;
        for(int i = 1; i <= n; ++i){
            sm[i] = sm[i - 1] + A[i - 1];
            if(i >= L) lm[i] = std::max(lm[i - 1], sm[i] - sm[i - L]);
            if(i >= M) mm[i] = std::max(mm[i - 1], sm[i] - sm[i - M]);
            if(i >= L+M) res = std::max(res, std::max(sm[i] - sm[i - L] + mm[i - L], sm[i] - sm[i - M] + lm[i - M]));
        }
        return res;
    }
};
