class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int,int>m({{0,1}});
        int cnt = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            cnt += nums[i];
            res += m[cnt - k];
            ++m[cnt];
        }
        return res;
    }
};
