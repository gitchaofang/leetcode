class Solution {
public:
    bool dfs(const std::string& str, const std::vector<std::string>& dict){
        if(str == "") return true;
        if(visited.find(str) != visited.end()) return false;
        for(const std::string& s: dict){
            if(s.size() > str.size() || str.substr(0,s.size()) != s) continue;
            if(dfs(str.substr(s.size()), dict)) return true;
        }
        visited.insert(str);
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s,wordDict);
    }
private:
    std::unordered_set<std::string> visited;
};
