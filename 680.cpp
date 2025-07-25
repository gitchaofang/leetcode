class Solution {
public:
    bool isValid(const std::string& s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
                return isValid(s, left + 1, right) || isValid(s, left, right - 1);
            }
            ++left;
            --right;
        }
        return true;
    }
};
