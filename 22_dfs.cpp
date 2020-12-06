class Solution {
public:
    void dfs(std::string str, const int& cnt, const int& n, std::vector<std::string>& res){
        int len = str.size();
        if(len == 2 * n){
            if(cnt == n) res.push_back(str);
            return;
        }
       
        if(cnt < n) dfs(str + '(', cnt + 1, n, res);
        if(len - cnt < cnt) dfs(str + ')', cnt, n, res);
        return;
    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        dfs("",0,n,res);
        return res;
    }
};
