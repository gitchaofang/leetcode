class Solution {
public:
    std::vector<std::vector<int>> dfs(const int& pos, const int& k, const int& n){
        if(k == 1){
            if(pos == n) return {{pos}};
            return {};
        }
        std::vector<std::vector<int>> res;
        for(int i = pos + 1; i <= 9; ++i){
            if(i + pos > n) break;
            std::vector<std::vector<int>> v = dfs(i, k - 1, n - pos);
            for(std::vector<int>& tv: v){
                tv.insert(tv.begin(), pos);
                res.push_back(tv);
            }
        }
        return res;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> res;
        for(int i = 1; i <= 9; ++i){
            std::vector<std::vector<int>> v = dfs(i, k, n);
            if(!v.empty()) res.insert(res.end(),v.begin(),v.end());
        }
        return res;
    }
};
