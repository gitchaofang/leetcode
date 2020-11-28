class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n <= 1) return n;
        std::queue<std::pair<int,int>> q;
        for(int i = 0; i < n; ++i){
            q.push({i,i});
            if(i != n - 1 && s[i] == s[i + 1]) q.push({i,i + 1}); 
        }
        int res = 0;
        while(!q.empty()){
            std::pair<int,int> p = q.front();
            q.pop();
            ++res;
            if(p.first >0 && p.second < n - 1 && s[p.first - 1] == s[p.second + 1]) q.push({p.first - 1, p.second + 1});
        }
        return res;
    }
};
