class Solution {
public:
    int dfs(const std::vector<std::vector<int>>& word_cnt, const int& pos, std::vector<int>& cnt, const std::vector<int>& sc){
        if(pos >= word_cnt.size()) return 0;
        int res = 0;
        for(int i = pos; i < word_cnt.size(); ++i){
            bool sucess = true;
            for(int j = 0; j < 26; ++j){
                if(word_cnt[i][j] > cnt[j]) sucess = false;
                cnt[j] -= word_cnt[i][j];
            }
            if(sucess){
                int d = sc[i] + dfs(word_cnt, i + 1, cnt, sc);
                res = std::max(res,d);
            }
            for(int j = 0; j < 26; ++j) cnt[j] += word_cnt[i][j];   
        }
        return res;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        std::vector<std::vector<int>> word_cnt;
        std::vector<int> sc;
        std::vector<int> cnt(26,0);
        for(const char& c: letters) ++cnt[c - 'a'];
        for(const std::string& str: words){
            std::vector<int> v(26,0);
            int ct = 0;
            for(const char& c: str){ 
                ++v[c - 'a'];
                ct += score[c - 'a'];
            }
            word_cnt.push_back(v);
            sc.push_back(ct);
        }
        return dfs(word_cnt, 0, cnt, sc);
    }
};
