class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        std::vector<int> left(n,0);
        std::vector<int> right(n,0);
        for(int i = 1; i < n; ++i){
            left[i] = std::max(left[i - 1], height[i - 1]);
            right[n - 1 - i] = std::max(right[n - i], height[n - i]);
        }
        int res = 0;
        for(int i = 1; i < n - 1; ++i){
            res += std::max(std::min(left[i], right[i]) - height[i], 0);
        }
        return res;
    }
};
