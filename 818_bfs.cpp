class Solution {
public:
    int racecar(int target) {
        if(target == 0) return 0;
        std::unordered_set<std::string> visited({"0-1"});
        int cnt = -1;
        std::queue<std::pair<int,int>>q({{0,1}});
        while(!q.empty()){
            ++cnt;
            for(int s = q.size(); s > 0; --s){
                std::pair<int,int> cur = q.front();
                q.pop();
                if(cur.first == target) return cnt;
                /*A*/
                int new_pos = cur.first + cur.second;
                int new_speed = cur.second * 2;
                std::string key = std::to_string(new_pos) + '-' + std::to_string(new_speed);
                if(new_pos > 0 && new_pos < 2 *target && visited.find(key) == visited.end()){
                    q.push({new_pos, new_speed});
                    visited.insert(key);
                }
                
                /*R*/
                new_speed = (cur.second > 0) ? -1 : 1;
                key = std::to_string(cur.first) + '-' + std::to_string(new_speed);
                if(visited.find(key) == visited.end()){
                    q.push({cur.first, new_speed});
                    visited.insert(key);
                }
            }        
        }
        return -1;
    }
};
