class Solution {
public:
    int binary_search(const std::vector<int>& nums, const int& targ){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == targ) return mid;
            if(nums[mid] > targ) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
    bool dfs(const int& cur, const int& k, const std::vector<int>& nums, std::vector<std::unordered_set<int>>& visited){
        if(cur == nums.size() - 1) return true;
        if(visited[cur].find(k) != visited[cur].end()) return false;
        for(int jump = k - 1; jump <= k + 1; ++jump){
            if(jump <= 0) continue;
            int pos = binary_search(nums, nums[cur] + jump);
            if(pos == -1 || visited[pos].find(jump) != visited[pos].end()) continue;
            if(dfs(pos, jump, nums, visited)) return true;
        }
        visited[cur].insert(k);
        return false;
    }
    bool canCross(vector<int>& stones) {
        std::vector<std::unordered_set<int>> visited(stones.size());
        return dfs(0,0,stones,visited);   
    }
};
