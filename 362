class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        m[0] = 0;   
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        m[timestamp] = m.rbegin() -> second + 1; 
        if(timestamp >= 300){
            auto pos = m.upper_bound(timestamp - 300);
            --pos;
            m.erase(m.begin(),pos);
        }
        return;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        if(timestamp >= 300){
            auto pos = m.upper_bound(timestamp - 300);
            --pos;
            m.erase(m.begin(), pos);
        }    
        return m.rbegin() -> second - m.begin() -> second;
    }
private:
    std::map<int,int>m;
};
