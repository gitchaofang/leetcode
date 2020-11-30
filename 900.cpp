class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        for(int i = 0; i < A.size(); i += 2){
            if(A[i] == 0) continue;
            v.push_back(A[i]);
            v.push_back(A[i + 1]);
        }  
        pos = 1;
        cnt = 0;   
    }
    
    int next(int n) {
        cnt += n;
        while(pos < v.size() && cnt > v[pos - 1]){
            cnt -= v[pos - 1];
            pos += 2;
        }
        return pos >= v.size() ? -1 : v[pos];
    }
private:
    std::vector<int> v;
    int cnt;
    int pos;
};
