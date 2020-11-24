class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        std::unordered_map<std::string, std::vector<std::string>>m;
        for(const std::string& str: strings){
            int gap = str[0] - 'a';
            std::string s = str;
            for(char& c: s) c = (c - gap + 26) % 26;
            m[s].push_back(str);
        }
        std::vector<std::vector<std::string>> res;
        for(auto it = m.begin(); it != m.end(); ++it) res.push_back(it -> second);
        return res;
    }
};

