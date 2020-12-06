class Solution {
public:
    std::vector<std::vector<int>> dfs(const std::vector<int>& nums,const int& cur){
        if(cur == nums.size() - 1) return {{nums[cur]}};
        std::unordered_set<int> visited;
        std::vector<std::vector<int>> res({{nums[cur]}});
        for(int i = cur + 1; i < nums.size(); ++i){
            if(visited.find(nums[i]) != visited.end()) continue;
            std::vector<std::vector<int>> v = dfs(nums,i);
            for(std::vector<int>& tv: v){
                tv.push_back(nums[cur]);
                res.push_back(tv);
            }
        }
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        std::unordered_set<int> visited;
        std::vector<std::vector<int>> res{{}};
        for(int i = 0; i < nums.size(); ++i){
            if(visited.find(nums[i]) != visited.end()) continue;
            std::vector<std::vector<int>> v = dfs(nums,i);
            res.insert(res.end(), v.begin(), v.end());
        }
        return res;
    }
};
