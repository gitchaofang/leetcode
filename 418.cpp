class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        std::string all("");
        for(const std::string& str: sentence) all += str + ' ';
        int n = all.size();
        int cnt = 0;
        for(int i = 0; i < rows; ++i){
            cnt += cols;
            if(all[cnt % n] == ' ') ++cnt;
            else{
                while(cnt > 0 && all[(cnt - 1) % n ] != ' ') --cnt;
            }
        }
        return cnt / n;
    }
};
