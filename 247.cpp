class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n == 1) return {"0","1","8"};
        std::vector<std::pair<char,char>> digit({{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}}); 
        std::queue<std::string> q({"","0", "1","8"});
        std::vector<std::string> res;
        while(!q.empty()){
            std::string str = q.front();
            q.pop();
            if(str.size() == n && str[0] != '0') res.push_back(str);
            for(const std::pair<char,char>& dig: digit){
                std::string next = dig.first + str + dig.second;
                if(next.size() <= n) q.push(next);
            }
        }
        return res;
    }
};
