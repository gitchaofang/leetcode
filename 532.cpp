class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int cnt = 0;
        std::unordered_set<int> visited;
        for(int i = 0; i < nums.size(); ++i){
            int d = nums[i];
            if(visited.find(d - k) != visited.end()){ 
                ++cnt;
                int j = i + 1;
                while(j < nums.size() && nums[j] == d) ++j;
                i = j - 1;
            }
            visited.insert(d);
        }
        return cnt;
    }
};
