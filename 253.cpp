class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::vector<std::pair<int,int>>v;
        for(const std::vector<int>& tv: intervals){
            v.push_back({tv[0],0});
            v.push_back({tv[1],1});
        }
        std::sort(v.begin(), v.end(),[](const std::pair<int,int>& p1, const std::pair<int,int>& p2){
            return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;
        });
        int room = 0;
        int cnt = 0;
        for(const std::pair<int,int>& p: v){
            if(p.second == 1) ++room;
            else if(room != 0) --room;
            else ++cnt;
        }
        return cnt;
    }
};
