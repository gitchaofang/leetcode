class Solution {
public:
    std::vector<std::vector<int>> dfs(int k, const int& targ, const int& pos){
        if(k == 1 && targ >= pos && targ <= 9) return{{targ}};
        std::vector<std::vector<int>> res;
        for(int i = pos; i <= 9; ++i){
            if(i > targ) return res;
            std::vector<std::vector<int>> v = dfs(k - 1, targ - i, i + 1);
            if(v.empty()) continue;
            for(std::vector<int>& sv: v){
                sv.insert(sv.begin(), i);
                res.push_back(sv);
            }
        }
        return res;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        return dfs(k, n, 1);
    }
};
