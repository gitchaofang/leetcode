class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        int row = image.size();
        int col = image[0].size();
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        std::queue<std::pair<int,int>> q({{sr,sc}});
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        while(!q.empty()){
            std::pair<int,int> p = q.front();
            q.pop();
            for(const std::pair<int,int>& dir: dire){
                int x = dir.first + p.first;
                int y = dir.second + p.second;
                if(x < 0 || x >= row || y < 0 || y >= col || image[x][y] != color) continue;
                image[x][y] = newColor;
                q.push({x,y});
            }
        }
        return image;
    }
};
