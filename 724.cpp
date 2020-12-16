class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> left(n,0);
        std::vector<int> right(n,0);
        for(int i = 0; i < n; ++i){
            if(i == 0){
                left[i] = nums[i];
                right[n - 1 - i] = nums[n - 1 - i];
            }
            else{
                left[i] = left[i - 1] + nums[i];
                right[n - 1 - i] = right[n - i] + nums[n - 1 - i];
            }
        }
        for(int i = 0; i < n; ++i){
            if(left[i] == right[i]) return i;
        }
        return -1;
    }
};
