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
        if(pos.size() > neg.size()) return pos.top();
        return double(pos.top() - neg.top()) / 2.0;
    }
private:
    std::priority_queue<int, std::vector<int>> pos;
    std::priority_queue<int, std::vector<int>> neg;
};
