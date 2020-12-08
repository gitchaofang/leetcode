class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        std::unordered_map<char, std::vector<std::string>>m;
        for(const std::string& str: words) m[str[0]].push_back(str);
        int res = 0;
        for(const char& c: S){
            if(m.find(c) == m.end()) continue;
            std::vector<std::string>tv;
            for(const std::string& str: m[c]){
                if(str.size() == 1) ++res;
                if(str[1] != c) m[str[1]].push_back(str.substr(1));
                else tv.push_back(str.substr(1));
            }
            m[c] = tv;
            
        }
        return res;
    }
};
