class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x == INT_MAX) return false;
        int64_t ori = x;
        int64_t d = 0;
        while(x != 0){
            d = d*10 + x % 10;
            x /= 10;
        }
        return ori == d;
    }
};
