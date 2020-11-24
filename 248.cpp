class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        std::vector<std::pair<char,char>> dig({{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}});
        int cnt = 0;
        if(low == "0"){
            cnt = 1;
            low = "1";
        }
        std::queue<std::string> q({""});
        for(int i = 0; i <= 3; ++i){
            if(i == 2) continue;
            if(high.size() > 1 || dig[i].first - '0' <= high[0] - '0') q.push(std::string(1,dig[i].first));
        }
        while(!q.empty()){
            for(int s = q.size(); s > 0; --s){
                std::string str = q.front();
                q.pop();
                if(str[0] != '0' && ((str.size() == low.size() && str >= low) || (str.size() > low.size()))){ 
                    ++cnt;
                }
                for(const std::pair<char,char>& p: dig){
                    std::string s = p.first + str + p.second;
                    if(s.size() > high.size() || (s.size() == high.size() && s > high)) break;
                    q.push(s);
                }
            }
        }
        return cnt;
    }
};
