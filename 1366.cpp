class Solution {
public:
    string rankTeams(vector<string>& votes) {
        std::unordered_map<int, std::unordered_map<char, int>>m;
        int n = votes.size();
        int l = votes[0].size();
        std::unordered_set<char>st;
        for(int i = 0; i < l; ++i){
            for(int j = 0; j < n; ++j){ 
                ++m[i][votes[j][i]];
                st.insert(votes[j][i]);
            }
        }    
        
        auto cmp = [&](const char& c1, const char& c2){
            for(int i = 0; i < l; ++i){
                if(m[i].find(c1) == m[i].end() && m[i].find(c2) == m[i].end()) continue;
                if(m[i].find(c2) == m[i].end()) return true;
                if(m[i].find(c1) == m[i].end()) return false; 
                if(m[i][c1] == m[i][c2]) continue;
                return m[i][c1] > m[i][c2];
            }
            return  c1 < c2;;
        };
        
        
        std::string str("");
        for(const char&c: st) str+=c;
        std::cout << str << '\n';
        std::sort(str.begin(),str.end(),cmp);
        return str;
    }
};
