class Solution {
public:
    int racecar(int target) {
        if(target == 0) return 0;
        std::queue<std::pair<int,int>> q({{0,1}});
        std::unordered_set<std::string>visited({"0-1"});
        int cnt = 0;
        while(!q.empty()){
            ++cnt;
            for(int s = q.size(); s > 0; --s){
                std::pair<int,int> cur = q.front();
                q.pop();
                /*A*/
                int next_pos = cur.first + cur.second;
                if(next_pos == target) return cnt;
                int next_speed = 2 * cur.second;
                std::string key = std::to_string(next_pos) + '-' + std::to_string(next_speed);
                if(next_pos > 0  && next_pos < 2 * target && visited.find(key) == visited.end()){ 
                    q.push({next_pos,next_speed});
                    visited.insert(key);
                }
                
                /*R*/
                next_speed = (cur.second > 0) ? -1 : 1;
                key = std::to_string(cur.first) + '-' + std::to_string(next_speed);
                if(visited.find(key) == visited.end()){
                    q.push({cur.first,next_speed});
                    visited.insert(key);
                }
            }
        }
        return -1;
    }
};
