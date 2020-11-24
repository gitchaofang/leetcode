class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int zeros = 0;
        int left = 0;
        int res = 0;
        for(int i = 0; i<n; ++i){
            if(A[i] == 0) ++zeros;
            if(zeros <= K) res = std::max(res, i - left + 1);
            while(zeros > K){
                if(A[left++] == 0) --zeros; 
            }
        }
        return res;
    }
};
