class Solution {
public:
    string longestWord(vector<string>& words) {
        std::unordered_set<std::string>m({""});
        auto cmp = [](const std::string& str1, const std::string& str2){
            return str1.size() == str2.size() ? str1 < str2 : str1.size() < str2.size();
        };
        std::sort(words.begin(),words.end(),cmp);
        std::string res("");
        for(const std::string& word: words){
            std::string str = word;
            str.pop_back();
            if(m.find(str) != m.end()){ 
                m.insert(word);
                if(word.size() > res.size()) res = word;
            }
        }
        return res;
    }
};
