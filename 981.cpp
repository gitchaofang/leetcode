class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].insert({timestamp,value});    
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";
        std::map<int,std::string>& m = store[key];
        if(m.empty()) return "";
        auto it = m.lower_bound(timestamp);
        if(it != m.end() && it -> first == timestamp) return it -> second;
        if(it == m.end() || it != m.begin()){
            it = std::prev(it);
            return it -> second;
        }
        return "";
    }
private:
    std::unordered_map<std::string, std::map<int, std::string>>store;
};
