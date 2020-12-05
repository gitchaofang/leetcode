struct cmp{
    bool operator()(const std::pair<int,int>& p1, const std::pair<int,int>& p2){
        return p1.first < p2.first;
    }  
};
int binary_search(const std::vector<int>& v, int left, const int& targ){
    int right = v.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(v[mid] == targ) return mid;
        if(v[mid] < targ) ++left;
        else --right;
    }
    return -1;
}
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        std::vector<std::unordered_set<int>> visited(n);
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,cmp> pq;
        pq.push({0,0});
        visited[0].insert(0);
        while(!pq.empty()){
            std::pair<int,int> cur = pq.top();
            pq.pop();
            for(int i = -1; i <= 1; ++i){
                int new_k = cur.second + i;
                if(new_k < 0) continue;
                int next = binary_search(stones, cur.first, stones[cur.first] + new_k);
                if(next == n - 1) return true;
                if(next == -1 || visited[next].find(new_k) != visited[next].end()) continue;
                pq.push({next, new_k});
                visited[next].insert(new_k);
            }
        }
        return false;
    }
};
