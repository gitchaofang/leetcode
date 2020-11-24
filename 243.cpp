class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        std::unordered_map<std::string, int>m;
        int dis = INT_MAX;
        for(int i = 0; i < words.size(); ++i){
            if(words[i] == word1){
                m[word1] = i;
                if(m.find(word2) != m.end()) dis = std::min(dis, i - m[word2]);
            }
            else if(words[i] == word2){
                m[word2] = i;
                if(m.find(word1) != m.end()) dis = std::min(dis, i - m[word1]);
            }
        }
        return dis;
    }
};
