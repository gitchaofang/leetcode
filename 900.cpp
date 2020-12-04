class RLEIterator {
public:
    RLEIterator(vector<int>& A): v(A), cur({0,0}) {
        
    }
    
    int next(int n) {
        while(cur.first < v.size() && n != 0){
            if(cur.second + n > v[cur.first]){
                n -= (v[cur.first] - cur.second);
                cur.first += 2;
                cur.second = 0;
            }
            else{
                cur.second += n; 
                n = 0;
            }
        }
        if(cur.first < v.size()) return v[cur.first + 1];
        return -1;
    }
private:
    std::vector<int>v;
    std::pair<int,int> cur;
};
