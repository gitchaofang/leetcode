class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        std::unordered_map<std::string, int>m;
        for(const std::string& str: d) m[str] = 0;
        for(const char& c: s){
            for(const std::pair<std::string,int>& p: m){
                if(p.second < p.first.size() && p.first[p.second] == c) ++m[p.first];
            }
        }
        std::string res("");
        for(const std::pair<std::string, int>& p: m){
            if(p.second == p.first.size()){
                if(res.size() < p.first.size() || (res.size() == p.first.size() && res > p.first)) res = p.first;
            }
        }
        return res;
    }
};
