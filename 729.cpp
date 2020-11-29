class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(m.empty() || end <= m.begin() -> first ||start >= m.rbegin() -> second){
            m.insert({start,end});
            return true;
        }
        auto it = m.lower_bound(start); 
        if(it == m.begin() || it == m.end() || it -> first < end) return false;
        it = std::prev(it);
        if(it -> second > start) return false;
        m.insert({start,end});
        return true;
    }
private:
    std::map<int,int> m;
};

