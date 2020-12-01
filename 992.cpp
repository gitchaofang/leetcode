class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        std::unordered_map<int,int>r;
        std::unordered_map<int,int>l;
        std::pair<int,int>p({-1,-1});
        int n = A.size();
        int res = 0;
        for(int i = 0; i < n; ++i){
            while(p.first < n - 1 && l.size() < K) ++l[A[++p.first]];
            while(p.second < n - 1 && r.size() <= K) ++r[A[++p.second]];
            if(r.size() == K) res += p.second - p.first + 1;
            else if(r.size() > K) res += p.second - p.first;
            if(--r[A[i]] == 0) r.erase(A[i]);
            if(--l[A[i]] == 0) l.erase(A[i]);
        }
        return res;
    }
};
