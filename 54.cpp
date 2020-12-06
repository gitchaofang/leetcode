class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::pair<int,int> row({0,matrix.size() - 1});
        std::pair<int,int> col({0,matrix[0].size() - 1});
        int sig = 0;
        std::vector<int> res;
        while(row.first <= row.second && col.first <= col.second){
            if(sig == 0){
                for(int i = col.first; i <= col.second; ++i) res.push_back(matrix[row.first][i]);
                ++row.first;
            }   
            else if(sig == 1){
                for(int i = row.first; i <= row.second; ++i)res.push_back(matrix[i][col.second]);
                --col.second;  
            }
            else if(sig == 2){
                for (int i = col.second; i >= col.first; --i) res.push_back(matrix[row.second][i]);
                --row.second;
            }
            else {
                for (int i = row.second; i >= row.first; --i) res.push_back(matrix[i][col.first]);
                ++col.first;
            }
            sig = (sig + 1) % 4;
        }
        return res;
    }
};
