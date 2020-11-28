class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n <= k) return arr;
        int left = 0;
        int right = n - 1;
        while(right - left + 1 > k){
            if(std::abs(arr[left] - x) <= std::abs(arr[right] - x)) --right;
            else ++left;
        }
        return std::vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};
