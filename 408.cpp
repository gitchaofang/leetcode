class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int pos = 0;
        for(int i = 0; i < abbr.size(); ++i){
            if(word[pos] == abbr[i]){
                ++pos;
                continue;
            }else if(abbr[i]>='a' && abbr[i] <= 'z') return false;
            int cnt = 0;
            if(abbr[i] == '0') return false;
            while(i < abbr.size() && abbr[i] >= '0' && abbr[i] <= '9'){
                cnt = cnt * 10 + (abbr[i++] - '0');
            }
            pos += cnt;
            if(pos > word.size()) return false;
            --i;
        }
        return pos == word.size();
    }
};
