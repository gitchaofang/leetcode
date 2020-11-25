class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pos.push(num);
        neg.push(-pos.top());
        pos.pop();
        if(pos.size() < neg.size()){
            pos.push(-neg.top());
            neg.pop();
        }
        return;
    }
    
    
    double findMedian() {
        return (pos.size() == neg.size()) ? double(pos.top() - neg.top()) / 2.0 : pos.top();    
    }
private:
    std::priority_queue<int> pos;
    std::priority_queue<int> neg;
};

