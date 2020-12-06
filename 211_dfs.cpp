struct Trie{
    std::unordered_map<char, Trie*> next;
    bool is_word;
    Trie(): is_word(false){}
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary(): root(new Trie()), cap(0) {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        cap = std::max(cap, int(word.size()));
        Trie* head = root;
        for(const char& c: word){
            if(head -> next.find(c) == head -> next.end()){
                Trie* node = new Trie();
                head -> next[c] = node;
                head = node;
            }
            else head = head -> next[c];
        }
        head -> is_word = true;
        return;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool dfs(Trie* root, const std::string& str){
        if(str == ""){
            if(root -> is_word) return true;
            return false;
        }
        std::string sstr = str.substr(1);
        if(str[0] !='.'){
            if(root -> next.find(str[0]) == root -> next.end()) return false;
            return dfs(root -> next[str[0]], sstr);
        }
        
        for(const std::pair<char,Trie*>&p : root -> next){
            if(dfs(p.second, sstr)) return true;
        }
        return false;
    }
    bool search(string word) {
        return dfs(root, word);   
    }
private:
    Trie* root;
    int cap;
};
