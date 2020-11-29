class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        std::unordered_set<std::string> visited;
        for(const std::string& str: deadends) visited.insert(str);
        if(visited.find("0000") != visited.end()) return -1;
        if(target == "0000") return 0;
        visited.insert("0000");
        std::queue<std::string> q({"0000"});
        int cnt = 0;
        while(!q.empty()){
            ++cnt;
            for(int s = q.size(); s > 0; --s){
                std::string str = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i){
                    std::string ns = str;
                    ns[i]  = '0' + (str[i] - '0' + 1) % 10;
                    if(visited.find(ns) == visited.end()){ 
                        if(ns == target) return cnt;
                        visited.insert(ns);
                        q.push(ns);
                    }
                    ns[i] = '0' + (str[i] - '0' + 9) % 10;
                    if(visited.find(ns) == visited.end()){ 
                        if(ns == target) return cnt;
                        visited.insert(ns);
                        q.push(ns);
                    }
                }
            }
        }
        return -1;   
    }
};
