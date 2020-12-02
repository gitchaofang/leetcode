lass Solution {
public:
    int dfs(const std::vector<int>& nums, const int& pos){
        if(pos == nums.size()) return 0;
        if(m.find(pos) != m.end()) return m[pos];
        int res = 1;
        for(int i = pos + 1; i < nums.size(); ++i){
            if(nums[i] > nums[pos]) res = std::max(res, 1 + dfs(nums,i));
        }
        m[pos] = res;
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) res = std::max(dfs(nums,i), res);
        return res;
    }
private:
    std::unordered_map<int,int>m;
};
