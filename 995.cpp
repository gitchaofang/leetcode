class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        std::vector<int> flip(n + 1, 0);
        int res = 0;
        for(int i = 1; i <= n; ++i){
            flip[i] = flip[i - 1];
            int d = flip[i];
            if(i > K) d -= flip[i - K];
            if((A[i - 1] == 1 && d %2 != 0) || (A[i - 1] == 0 && d % 2 == 0)){
                if(i + K - 1 > n)return -1;
                ++flip[i]; 
                ++res;
            }
        }
        return res;
    }
};
