class Solution {
public:
    std::pair<string ,std::vector<int>> make_count(const std::string& str){
        std::vector<int> v;
        std::string head("");
        for(int i = 0; i < str.size(); ++i){
            head += str[i];
            int j = i;
            while(j < str.size() && str[j] == str[i]) ++j;
            v.push_back(j - i);
            i = j - 1;
        }
        return {head, v};
    }
    int expressiveWords(string S, vector<string>& words) {
        std::pair<std::string, std::vector<int>> stand = make_count(S);
        int res = 0;
        for(const std::string& str: words){
            std::pair<std::string, std::vector<int>> p = make_count(str);
            if(p.first != stand.first) continue;
            bool sucess = true;
            for(int i = 0; i < p.second.size(); ++i){
                int cnt = p.second[i];
                int stand_cnt = stand.second[i];
                if(cnt == stand_cnt || (cnt < stand_cnt && stand_cnt >= 3)) continue;
                sucess = false;
                break;
            }
            if(sucess) ++res;
            
        }
        return res;
    }
};
