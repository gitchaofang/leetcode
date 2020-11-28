struct  cmp{
    bool operator()(const int& d1, const int& d2){
        return d1 > d2;
    }  
};
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums): cap(k) {
        for(const int& d: nums) add(d);    
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > cap) pq.pop();
        return pq.top();
    }
private:
    priority_queue<int,std::vector<int>, cmp> pq;
    int cap;
};

