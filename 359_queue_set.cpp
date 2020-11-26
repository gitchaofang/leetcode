class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while(!q.empty() && q.front().first <= timestamp - 10){
            name.erase(q.front().second);
            q.pop();
        }
        if(name.find(message) == name.end()){
            q.push({timestamp, message});
            name.insert(message);
            return true;
        }
        return false;
    }
private:
    std::unordered_set<std::string> name;
    std::queue<std::pair<int,std::string>> q;
};

