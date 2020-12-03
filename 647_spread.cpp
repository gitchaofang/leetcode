class Solution {
public:
    int count(const std::string& str, std::pair<int,int> p){
        while(p.first > 0 && p.second < str.size() - 1 && str[p.first - 1] == str[p.second + 1]) {
            --p.first;
            ++p.second;
        }
        return (p.second + 2 - p.first) / 2;
    }
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            res += count(s, {i,i});
            if(i < s.size() - 1 && s[i] == s[i + 1]) res += count(s,{i, i + 1}); 
        }
        return res;
    }
};
