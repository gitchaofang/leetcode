class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        std::multiset<int> ms;
        int left = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            ms.insert(nums[i]);
            while(*ms.rbegin() - *ms.begin() > limit){
                ms.erase(ms.find(nums[left++]));
            }
            res = std::max(res, i -  left + 1);
        }
        
        return res;
    }
};
