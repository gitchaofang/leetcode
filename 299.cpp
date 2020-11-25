class Solution {
public:
    string getHint(string secret, string guess) {
        std::unordered_map<int,int> m;
        for(const int&d: secret) ++m[d];
        int b = 0;
        for(int i = 0; i < secret.size(); ++i){
            if(secret[i] == guess[i]){
                ++b;
                --m[secret[i]];
                if(m[secret[i]] == 0) m.erase(secret[i]);
            }
        }
        int c = 0;
        for(int i = 0; i < guess.size(); ++i){
            if(guess[i] == secret[i] || m[guess[i]] == 0) continue;
            ++c;
            --m[guess[i]]; 
        }
        return std::to_string(b) + 'A' + std::to_string(c) + 'B';
    }
};
