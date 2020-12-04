class FreqStack {
public:
    FreqStack(): maxfreq(0) {
        
    }
    
    void push(int x) {
        ++cnt[x];
        freq[cnt[x]].push(x);
        maxfreq = std::max(maxfreq,cnt[x]);
        return;
    }
    
    int pop() {
        int top = freq[maxfreq].top();
        freq[maxfreq].pop();
        if(freq[maxfreq].empty())freq.erase(maxfreq--);
        if(--cnt[top] == 0) cnt.erase(top);
        return top;
    }
private:
    std::unordered_map<int,int> cnt;
    std::unordered_map<int,std::stack<int>> freq;
    int maxfreq;
};
