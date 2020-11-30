class Solution {
public:
    int match(const std::string& ori, const std::string& str){
        int cnt = 0;
        for(int i = 0; i < std::min(int(ori.size()), int(str.size())); ++i){
            if(ori[i] == str[i]) ++cnt;
        }
        return cnt;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while(true){
            int pos = rand() % wordlist.size();
            std::string str = wordlist[pos];
            int match_num = master.guess(str);
            if(match_num == str.size()) return;
            std::vector<std::string> v;
            for(std::string& s: wordlist){
                if(s == str) continue;
                if(match(s, str) == match_num) v.push_back(s);
            }
            wordlist = v;
        }
        return;
    }
};
