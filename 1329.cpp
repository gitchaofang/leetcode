struct cmp{
    bool operator()(const int& d1, const int& d2){
        return d1 > d2;
    }
};
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        for(int i = row - 1; i >= 0; --i){
            std::priority_queue<int, std::vector<int>, cmp> pq;
            int l = 0;
            while(i + l < row && l < col) {
                pq.push(mat[i + l][l]);
                ++l;
            }
            l = 0;
            while(i + l < row && l < col){
                mat[i + l][l] = pq.top();
                pq.pop();
                ++l;
            }   
        }
        for(int j = 1; j < col; ++j){
            std::priority_queue<int,std::vector<int>,cmp>pq;
            int l = 0;
            while(l < row && j + l < col){ 
                pq.push(mat[l][j + l]);
                ++l;
            }
            l = 0;
            while(l < row && j + l < col){
                mat[l][j + l] = pq.top();
                pq.pop();
                ++l;
            }
        }
        return mat;
    }
};
