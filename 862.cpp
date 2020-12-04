struct cmp{
    bool operator()(const std::pair<int,int>& p1, const std::pair<int,int>& p2){
        return p1.first > p2.first;
    }  
};
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>, cmp> pq;
        pq.push({0,0});
        int cnt = 0;
        int res = INT_MAX;
        for(int i = 1; i <= A.size(); ++i){
            cnt += A[i - 1];
            while(!pq.empty() && cnt - pq.top().first >= K){
                res = std::min(i - pq.top().second, res);
                pq.pop();
            }
            pq.push({cnt, i});
        }
        return res == INT_MAX ? -1 : res;
    }
};
