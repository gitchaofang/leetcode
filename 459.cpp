class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i <= s.size()/2; ++i){
            if(n % i != 0) continue;
            std::string str = s.substr(i) + s.substr(0,i);
            if(str == s) return true;
        }   
        return false;
    }
};
