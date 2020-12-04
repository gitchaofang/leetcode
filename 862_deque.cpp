class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        std::deque<int> dq;
        int n = A.size();
        dq.push_front(0);
        std::vector<int> sm(n + 1, 0);
        int res = INT_MAX;
        for(int i = 1; i <= n; ++i){
            sm[i] = sm[i - 1] + A[i - 1];
            while(!dq.empty() && sm[i] - sm[dq.front()] >= K){
                res = std::min(res, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && sm[dq.back()] >= sm[i]) dq.pop_back();
            dq.push_back(i);
        }
        return res == INT_MAX ? -1: res;
    }
};
