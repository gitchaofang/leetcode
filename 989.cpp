class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int pos = A.size() - 1;
        std::vector<int> res;
        int extra = 0;
        while(pos >= 0 && K != 0){
            int d1 = A[pos--];
            int d2 = K % 10;
            K /= 10;
            res.insert(res.begin(), (d1 + d2 + extra) % 10);
            extra = (d1 + d2 + extra) / 10;
        }   
        while(pos >= 0){ 
            int d = A[pos--];
            res.insert(res.begin(), (d + extra) % 10);
            extra = (d + extra) / 10;
        }
        while(K != 0){
            int d = K % 10;
            K /= 10;
            res.insert(res.begin(), (d + extra) % 10);
            extra = (d + extra) / 10;
        }
        if(extra != 0) res.insert(res.begin(), extra);
        return res;
    }
};
