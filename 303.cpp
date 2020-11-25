class NumArray {
public:
    NumArray(vector<int>& nums) {
        sm.resize(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); ++i) sm[i] = sm[i - 1] + nums[i - 1];
    }
    
    int sumRange(int i, int j) {
        return sm[j + 1] - sm[i];
    }
private:
    std::vector<int> sm;
};
