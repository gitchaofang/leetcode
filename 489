class Solution {
public:
    void sweep(Robot& r, int x, int y, int dir){
        r.clean();
        std::string str(std::to_string(x) + '-' + std::to_string(y));
        visited.insert(str);
        for(int i = 0; i < 4; ++i){
            int cur = (i + dir) % 4;
            int nx = x + dire[cur].first;
            int ny = y + dire[cur].second;
            str = std::to_string(nx) + '-' + std::to_string(ny);
            if(visited.find(str) != visited.end() || !r.move()){ 
                r.turnRight();
                continue;
            }
            sweep(r,nx,ny,cur);
            r.turnLeft();
            r.turnLeft();
            r.move();
            r.turnLeft();
        }
        return;
    }
    void cleanRoom(Robot& robot) {
        dire = {{-1,0},{0,1},{1,0},{0,-1}};
        sweep(robot,0,0,0);
        return;
    }
private:
    std::unordered_set<std::string> visited;
    std::vector<std::pair<int,int>>dire;
};
