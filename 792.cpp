class Solution {
public:
    bool check(const std::vector<std::set<int>>& m, const std::string& str){
        int cur = -1;
        for(int i=0; i<str.size(); ++i){
            int c = str[i] - 'a';
            if(m[c].size() == 0) return false;
            int temp = cur;
            for(auto it = m[c].begin(); it != m[c].end(); ++it){
                if(*it <= cur) continue;
                temp = *it;
                break;
            }
            if(temp == cur) return false;
            cur = temp;
        }
        return true;
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        std::vector<std::set<int>> m(26,std::set<int>());
        int len = S.size();
        for(int i=0; i<len; ++i) m[S[i] - 'a'].insert(i);
        int res = 0;
        for(const std::string& str: words){
            if(check(m,str)){ 
                ++res;
                std::cout << str << '\n';
            }
        }
        return res;
    }
};
