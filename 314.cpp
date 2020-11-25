class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0) return {};
        std::multiset<int> st({nums.back()});
        std::vector<int> res({0});
        for(int i = nums.size() - 2; i >= 0; --i){
            auto it = st.lower_bound(nums[i]);
            if(it == st.end()) res.insert(res.begin(),nums.size() -1 - i);
            else res.insert(res.begin(), std::distance(st.begin(),it));
            st.insert(nums[i]);
        }
        return res;
    }
};
