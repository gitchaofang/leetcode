struct Trie{
    std::unordered_map<char,Trie*> nb;
    bool is_word;
    Trie(): is_word(false){}
};
class Solution {
public:
    void dfs(const std::vector<std::vector<char>>& board, std::string& str, const int& i, const int& j, Trie* root, std::unordered_set<std::string>& res){
        int row = board.size();
        int col = board[0].size();
        if(root -> nb.find(board[i][j]) == root ->nb.end()) return;
        str += board[i][j];
        root = root -> nb[board[i][j]];
        if(root -> is_word) res.insert(str);
        visited[i * col + j] = true;
        for(const std::pair<int,int>& dir: dire){
            int x = i + dir.first;
            int y = j + dir.second;
            if(x < 0 || x >= row || y < 0 || y >= col || visited[x * col + y] == true || root -> nb.find(board[x][y]) == root -> nb.end()) continue;
            dfs(board, str, x, y, root, res);
        }  
        visited[i * col + j] = false;
        str.pop_back();
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        /*build Trie*/
        for(const std::string& str: words){
            Trie* head = root;
            for(const char& c: str){
                if(head -> nb.find(c) == head -> nb.end()){
                    Trie* node = new Trie();
                    head -> nb[c] = node;
                    head = node;
                }
                else head = head -> nb[c];
            }
            head -> is_word = true;
        }
        
        /*query*/
        dire = {{0,-1},{-1,0},{0,1},{1,0}};
        int row = board.size();
        int col = board[0].size();
        visited.resize(row*col,false);
        std::unordered_set<std::string> res;
        std::string str("");
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){ 
                dfs(board,str,i,j,root,res);
            }
        }
        std::vector<std::string> v(res.begin(),res.end());
        return v;
    }
private:
    std::vector<std::pair<int,int>> dire;
    std::vector<bool> visited;
};
