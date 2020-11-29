class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        std::unordered_map<char, std::queue<std::string>>m;
        for(const std::string& word: words) m[word[0]].push(word);
        int res = 0;
        for(const char& c: S){
            if(m.find(c) == m.end()) continue;
            for(int s = m[c].size(); s > 0; --s){
                std::string str = m[c].front();
                m[c].pop();
                if(str.size() == 1) ++res;
                else m[str[1]].push(str.substr(1));
            }
        }
        return res;
    }
};
