struct cmp{
    bool operator()(const std::pair<int,int>& p1, const std::pair<int,int>& p2){
        return p1.first > p2.first;
    }
};
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, cmp>pq; 
        int cnt = 0;
        int res = INT_MAX;
        for(int i = 0; i < A.size(); ++i){
            cnt += A[i];
            if(cnt >= K) res = std::min(res, i + 1);
            while(!pq.empty() && cnt - pq.top().first >= K){
                res = std::min(res, i - pq.top().second);
                pq.pop();
            }
            pq.push({cnt,i});
        }
        return res == INT_MAX ? -1 : res;
    }
};
