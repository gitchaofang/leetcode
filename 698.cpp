class Solution {
public:
    bool dfs(const std::vector<int>& nums, const int& sm, const int& pos, const int& k, const int& targ, std::vector<bool>& visited){
        if(sm == targ) {
            if(k == 1) return true;
            return dfs(nums,0,0,k - 1,targ, visited);
        }
        for(int i = pos; i < nums.size(); ++i){
            if(sm + nums[i] > targ || visited[i] == true) continue;
            visited[i] = true;
            if(dfs(nums, sm + nums[i], i + 1, k, targ,visited)) return true;
            visited[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sm = std::accumulate(nums.begin(), nums.end(),0);
        if(sm % k != 0) return false;
        sm /= k;
        std::vector<bool> visited(nums.size(), false);
        return dfs(nums,0,0,k,sm,visited);   
    }
};
