class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int cnt = 0;
        int res = 0;
        int left = 0;
        for(int i = 0; i < A.size(); ++i){
            if(A[i] == 1 ) res = std::max(res,i - left + 1);
            else{
                ++cnt;
                if(cnt <= K) res = std::max(res,i - left + 1);
                else{
                    while(A[left] == 1) ++left;
                    --cnt;
                    ++left;
                }
            }
        }
        return res;
    }
};
