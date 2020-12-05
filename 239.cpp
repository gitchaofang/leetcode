class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> q;
        std::vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            while(!q.empty() && q.back() < nums[i]) q.pop_back();
            q.push_back(nums[i]);
            if(i >= k && q.front() == nums[i - k]) q.pop_front();
            if(i >= k - 1) res.push_back(q.front()); 
        }
        return res;
    }
};
