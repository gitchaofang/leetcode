class Solution {
public:
    void dfs(const int& sm, const int& k,const int& pos, std::vector<int>& cur,std::vector<std::vector<int>>& res, const int& n){
        if(k == cur.size()){
            if(sm == n) res.push_back(cur);
            return;
        }
        for(int i = pos; i <= 9; ++i){
            if(sm + i > n) return;
            cur[k] = i;
            dfs(sm + i, k + 1, i + 1, cur, res, n);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>>res;
        std::vector<int>cur(k);
        dfs(0, 0, 1,cur, res, n);
        return res;
    }
};
