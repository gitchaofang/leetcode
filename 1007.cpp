class Solution {
public:
    int check(const std::vector<int>& v, const std::vector<int>& u, const int& targ){
        int res= 0;
        for(int i = 0; i < v.size(); ++i){
            if(v[i] != targ && u[i] != targ) return v.size() + 1;
            res += (v[i] != targ);
        }
        return res;
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res = check(A, B, A[0]);
        res = std::min(res, check(A, B, B[0]));
        res = std::min(res, check(B, A, A[0]));
        res = std::min(res, check(B, A, B[0]));
        return res == A.size() +1 ? -1 : res;
    }
};
