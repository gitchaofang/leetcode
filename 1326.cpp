class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        std::map<int,int>  m;
        for(int i = 0; i < ranges.size(); ++i){
            int left = std::max(0, i - ranges[i]);
            int right = std::min(i + ranges[i], n);
            if(m.find(left) == m.end()) m[left] = right;
            else m[left] = std::max(right, m[left]);
        }
        
        int res = 1;
        auto it = m.begin();
        int far = it-> second;
        std::priority_queue<int>pq;
        for(;far < n; ++res){
            while(it != m.end() && it -> first <= far) {
                pq.push(it -> second);
                ++it;
            }
            if(pq.empty() || pq.top() <= far) return -1;
            far = pq.top();
            pq.pop();
        }
        return res == 0 ? - 1 : res;
    }
};
