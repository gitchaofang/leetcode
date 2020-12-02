class Solution {
public:
    std::vector<std::vector<int>> dfs(const std::vector<int>& nums, const int& pos){
        if(pos == nums.size()) return {{}};
        if(m.find(pos) != m.end()) return m[pos];
        std::unordered_set<int> st;
        std::vector<std::vector<int>> res({{nums[pos]}});
        for(int i = pos + 1; i < nums.size(); ++i){
            if(nums[i] < nums[pos] || st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            std::vector<std::vector<int>> v = dfs(nums,i);
            for(std::vector<int>& tv: v){
                tv.insert(tv.begin(), nums[pos]);
                res.push_back(tv);
            }
        }
        m[pos] = res;
        return res;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::unordered_set<int> visited;
        for(int i = 0; i < nums.size(); ++i){
            if(visited.find(nums[i]) != visited.end()) continue;
            visited.insert(nums[i]);
            std::vector<std::vector<int>> v = dfs(nums,i);
            for(const std::vector<int>& tv: v){
                if(tv.size() >= 2) res.push_back(tv);
            }
        }
        return res;
    }
private:
    std::unordered_map<int,std::vector<std::vector<int>>>m;
};
