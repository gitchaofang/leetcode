class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> st(nums.begin(),nums.end());
        int res = 0;
        for(const int& d: nums){
            if(st.find(d) == st.end()) continue;
            int left = d;
            int right = d;
            while(st.find(left - 1) != st.end()) st.erase(--left);
            while(st.find(right + 1) != st.end()) st.erase(++right);
            res = std::max(res, right - left + 1);
        }
        return res;
    }
};
