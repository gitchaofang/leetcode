class Solution {
public:
    int binary_search(const std::vector<int>& v, const int& targ){
        int left = 0; 
        int right = v.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(v[mid] == targ) return mid;
            if(v[mid] < targ) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        std::vector<std::unordered_set<int>> dp(n);
        dp[0].insert(0);
        std::queue<std::pair<int,int>> q({{0,0}});
        while(!q.empty()){
            std::pair<int,int> p = q.front();
            q.pop();
            for(int j = p.second - 1; j <= p.second + 1; ++j){
                if(j <= 0) continue;
                int next = stones[p.first] + j;
                int pos = binary_search(stones, next);
                if(pos == n - 1) return true;
                if(pos == -1 || dp[pos].find(j) != dp[pos].end()) continue;
                q.push({pos, j});
                dp[pos].insert(j);
            }
        }
        return false;
    }
};
