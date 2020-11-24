class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        std::queue<std::string> q;
        std::vector<pair<char,char>> dig({{'0','0'},{'1','1'},{'8','8'},{'9','6'},{'6','9'}});
        if(n % 2 == 0) q.push("");
        else{
            for(int i = 0; i < 3; ++i) q.push(std::string(1,dig[i].first));
        }
        for(int i = 1; i <= n/2; ++i){
            for(int j = q.size(); j > 0; --j){
                std::string str = q.front();
                q.pop();
                for(int l = (i == n/2) ? 1 : 0; l < 5; ++l) q.push(dig[l].first + str + dig[l].second);
                
            }
        }
        std::vector<std::string> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
        
    }
};

