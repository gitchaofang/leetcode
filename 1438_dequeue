class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        std::deque<int>mx;
        std::deque<int>mn;
        int left = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            while(!mx.empty() && mx.back() < nums[i]) mx.pop_back();
            while(!mn.empty() && mn.back() > nums[i]) mn.pop_back();
            mx.push_back(nums[i]);
            mn.push_back(nums[i]);
            while(mx.front() - mn.front() > limit){
                if(nums[left] == mx.front()) mx.pop_front();
                if(nums[left] == mn.front()) mn.pop_front();
                ++left;
            }
            res = std::max(res, i - left  +1);
        }
        return res;
    }
};
