class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        std::vector<std::pair<char,char>> dig({{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}});
        int cnt = 0;
        std::queue<std::string> q({"","0","1","8"});
        if(low == "0"){
            ++cnt;
            low = "1";
        }
        while(!q.empty()){
            std::string str = q.front();
            q.pop();
            if(str != "" && str[0] != '0' && (str.size() > low.size() ||(str.size() == low.size() && str >= low)) && (str.size() < high.size() || (str.size() == high.size() && str <= high))) ++cnt;
            for(const std::pair<char,char>& p: dig){
                std::string next = p.first + str + p.second;
                if(next.size() <= high.size()) q.push(next);
            }
        }
        return cnt;
    }
};
