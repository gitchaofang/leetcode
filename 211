class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary(): head(new Trie()){
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* root = head;
        for(const char& c: word){
            if((root -> next).find(c) == (root -> next).end()){
                Trie* node = new Trie();
                (root -> next).insert({c,node});
                root = node;
            }
            else root = (root -> next)[c];
        }
        root -> isWord = true;
        return;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        std::queue<Trie*>q({head});
        for(const char& c: word){
            for(int i = q.size(); i > 0; --i){
                Trie* node = q.front();
                q.pop();
                for(const std::pair<char, Trie*> p: node -> next){
                    if(c == '.') q.push(p.second);
                    else if(c == p.first) q.push(p.second);
                }
            }
        }
        while(!q.empty()){
            Trie* node = q.front();
            q.pop();
            if(node -> isWord) return true;
        }
        return false;
    }
private:
    struct Trie{
        std::unordered_map<char,Trie*> next;
        bool isWord;
        Trie(): isWord(false){}
    };
    Trie* head;
};
