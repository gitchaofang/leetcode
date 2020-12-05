class Solution {
public:
    bool dfs(const std::vector<int>& nums, const int& cur, const int& sm, const int& targ){
        if(sm == targ) return true;
        std::string str = std::to_string(sm) + '-' + std::to_string(cur);
        if(st.find(str) != st.end()) return false;
        std::unordered_set<int> visited;
        for(int i = cur; i < nums.size(); ++i){
            if(sm + nums[i] > targ) break;
            if(visited.find(nums[i]) != visited.end()) continue;
            visited.insert(nums[i]);
            if(dfs(nums,i + 1, sm + nums[i], targ)) return true;
        }
        st.insert(str);
        return false;
    }
    bool canPartition(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int sm = std::accumulate(nums.begin(), nums.end(),0);
        if(sm % 2 != 0) return false;
        sm /= 2;
        return dfs(nums, 0, 0, sm);
    }
std::unordered_set<std::string> st;
};
