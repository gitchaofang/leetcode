class Solution {
public:
    void dfs(std::string& str, const std::string& digit,const int& pos, std::vector<std::string>& res){
        if(pos == str.size()) res.push_back(str);
        for(const char& c: m[digit[pos]]){
            str[pos] = c;
            dfs(str, digit, pos + 1, res);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};  
        std::string str(digits.size(),'o');
        std::vector<std::string> res;
        dfs(str, digits, 0, res);
        return res;
    }
std::unordered_map<char,std::vector<char>>m;
};
