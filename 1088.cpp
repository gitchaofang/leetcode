lass Solution {
public:
    int dfs(const int64_t& num, const int64_t& rotate, const int& p, const int& N){
        if(num > N) return 0;
        int res = 0;
        res += dfs(num*10 + 0, rotate, p + 1, N);
        res += dfs(num*10 + 1, rotate + std::pow(10, p), p + 1, N);
        res += dfs(num*10 + 6, rotate + std::pow(10, p) * 9, p + 1, N);
        res += dfs(num*10 + 8, rotate + std::pow(10, p) * 8, p + 1, N);
        res += dfs(num*10 + 9, rotate + std::pow(10, p)* 6, p + 1, N);
        return num != rotate ? 1 + res: res;
    }
    int confusingNumberII(int N) {
        int res = 0;
        res += dfs(1, 1, 1, N);
        res += dfs(6, 9, 1, N);
        res += dfs(8, 8, 1, N);
        res += dfs(9, 6, 1, N);
        return res;
    }
};
