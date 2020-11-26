class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;
        std::unordered_map<int,int>m;
        int res = 0;
        int head = 0;
        ++m[s[0]];
        for(int i = 1; i < s.size(); ++i){
            ++m[s[i]];
            if(m.size() <= k) continue;
            res = std::max(res, i - head);
            while(m.size() > k){
                --m[s[head]];
                if(m[s[head]] == 0) m.erase(s[head]);
                ++head;
            }    
        }
        res = std::max(res, int(s.size()) - head);
        return res;
    }
};
