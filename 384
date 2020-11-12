class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::vector<int> v = arr;
        for(int i = 0; i < v.size(); ++i){
            int pos = rand() % (v.size() - i);
            std::swap(v[i],v[i + pos]);
        }
        return v;
    }
private:
    std::vector<int> arr;
};
