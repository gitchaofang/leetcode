class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < nums1.size() && j <nums2.size()){
            if(nums1[i] == nums2[j]){ 
                nums1[k++] = nums1[i++];
                ++j;
            }
            else if(nums1[i] > nums2[j]) ++j;
            else ++i;
        }
        return std::vector<int>(nums1.begin(), nums1.begin() + k);
    }
};
