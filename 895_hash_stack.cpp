class FreqStack {
public:
    FreqStack(): maxfreq(0) {
        
    }
    
    void push(int x) {
        ++m[x];
        freq[m[x]].push(x);
        if(m[x] > maxfreq) maxfreq = m[x];
        return;
    }
    
    int pop() {
        int top = freq[maxfreq].top();
        freq[maxfreq].pop();
        if(freq[maxfreq].empty()) --maxfreq;
        --m[top];
        return top;
    }
private:
    std::unordered_map<int,int> m;
    std::unordered_map<int,std::stack<int>> freq;
    int maxfreq;

};
