class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        int pre1 = 0;
        int pre2 = 1;
        for(int i = 2; i <=N; ++i){
            int d = pre2;
            pre2 += pre1;
            pre1 = d;
        }
        return pre2;
    }
};
