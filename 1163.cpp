class Solution {
public:
    string lastSubstring(string s) {
        std::string res("");
        std::map<char, std::vector<int>>m;
        for(int i = 0; i < s.size(); ++i) m[s[i]].push_back(i);
        if(m.size() == 1) return s;
        int n = s.size();
        while(!m.empty()){
            res += m.rbegin() -> first;
            std::map<char,std::vector<int>> tm;
            for(const int& d: m.rbegin() -> second){
                if(d + 1 < n) tm[s[d + 1]].push_back(d + 1);
            }
            m = tm;
        }
        return res;
    }
};
