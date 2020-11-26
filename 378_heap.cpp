struct cmp{
    bool operator()(const std::pair<int,int>& p1, const std::pair<int,int>& p2){
        return p1.first > p2.first; 
    }  
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, cmp> pq;
        pq.push({matrix[0][0],0});
        matrix[0][0] = INT_MAX;
        for(int i = 0; i < k - 1; ++i){
            int x = pq.top().second / col;
            int y = pq.top().second % col;
            pq.pop();
            if(x + 1 < row && matrix[x + 1][y] != INT_MAX){ 
                pq.push({matrix[x + 1][y], (x + 1) * col + y});
                matrix[x + 1][y] = INT_MAX;
            }
            if(y + 1 < col && matrix[x][y + 1] != INT_MAX){ 
                pq.push({matrix[x][y + 1], x * col + y + 1});
                matrix[x][y + 1] = INT_MAX;
            }
        }
        return pq.top().first;
    }
};
