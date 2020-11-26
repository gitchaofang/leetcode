class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): sm(0),cap(size) {
        
    }
    
    double next(int val) {
        q.push(val);
        sm += val;
        if(q.size() > cap){
            sm -= q.front();
            q.pop();
        }
        return double(sm) / double(q.size());
    }
private:
    std::queue<int> q;
    int sm;
    int cap;
};
