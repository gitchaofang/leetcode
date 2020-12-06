class Solution {
public:
    void dfs(const std::vector<int>& nums, vector<int>& v,const int& k, std::vector<std::vector<int>>& res, int & visited){
        if(k == v.size()){
            res.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            int mask = 1 << i;
            if((visited & mask) != 0) continue;
            visited |= mask;
            v[k] = nums[i];
            dfs(nums,v,k + 1,res,visited);
            visited ^= mask;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> v(n);
        std::vector<std::vector<int>>res;
        int visited = 0;
        dfs(nums,v,0,res,visited);
        return res;
    }
};
