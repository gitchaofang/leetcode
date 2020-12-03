class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        /*check overlap*/
        for(const std::pair<int,int>& p: overlap){
            if(!(end <= p.first || start >= p.second)) return false;
        }   
        /*open*/
        for(const std::pair<int,int>& p: open){
            if(end <= p.first || start >= p.second) continue;
            overlap.push_back({std::max(start, p.first), std::min(end,p.second)});
        }
        open.push_back({start,end});
        return true;
    }
private:
    std::vector<std::pair<int,int>> open;
    std::vector<std::pair<int,int>> overlap;
};

