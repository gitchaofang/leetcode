class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++freq[start];
        --freq[end];
        int cnt = 0;
        for(auto it = freq.begin(); it != freq.end(); ++it){
            cnt += it -> second;
            if(cnt >= 3){
                ++freq[end];
                --freq[start];
                return false;
            }
        }
        return true;
    }
private:
    std::map<int,int> freq;
};

