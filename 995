class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        std::vector<uint32_t> isflipped(n,0);
        int curflip = 0;
        int res = 0;
        for(int i=0; i<n; ++i){
            if(i >= K) curflip ^= isflipped[i - K];
            if(curflip % 2 == A[i]){
                if(i + K > n) return -1;
                isflipped[i] = 1;
                curflip ^= 1;
                A[i] = 1;
                ++res;
            }
        }
        return res;
    }
};
