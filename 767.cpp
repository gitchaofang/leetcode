struct cmp{
    bool operator()(const std::pair<char,int>& p1, const std::pair<char,int>& p2){
        return p1.second < p2.second;    
    }  
};
class Solution {
public:
    string reorganizeString(string S) {
        std::unordered_map<char,int> m;
        for(const char& c: S) ++m[c];
        std::priority_queue<std::pair<char,int>, std::vector<std::pair<char,int>>,cmp>pq(m.begin(),m.end());
        std::string res("");
        while(!pq.empty()){
            std::pair<char,int> p = pq.top();
            pq.pop();
            if(res == "" || res.back() != p.first){ 
                res += p.first;
                if(--p.second > 0) pq.push(p);
            }
            else{
                if(pq.empty()) return "";
                std::pair<char,int> p2 = pq.top();
                pq.pop();
                pq.push(p);
                res += p2.first;
                if(--p2.second > 0) pq.push(p2);
            }
        }
        return res; 
    }
};
