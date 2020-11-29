class Solution {
public:
    bool dfs(std::string& str, std::unordered_set<std::string>& visited, const int& n, const int& k){
        if(visited.size() == std::pow(k,n)) return true;
        str += " ";
        std::string ts = str.substr(str.size() - n);
        for(char c = '0' ; c < '0' + k; ++c){
            ts.back() = c;
            if(visited.find(ts) != visited.end()) continue;
            visited.insert(ts);
            str.back() = c;
            if(dfs(str, visited, n, k)) return true;
            visited.erase(ts);
        }
        str.pop_back();
        return false;
        
        
    }
    string crackSafe(int n, int k) {
        std::string str(n,'0');
        std::unordered_set<std::string> visited({str});   
        if(dfs(str, visited, n, k)) return str;
        return "";
    }
};
