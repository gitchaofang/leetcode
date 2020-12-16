class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int den = 1;
        if(expression[0] != '-') expression = '+' + expression;
        int n = expression.size();
        for(int i = 0; i < n; ++i){
            int sign = 1;
            if(expression[i] == '-') sign = -1;
            ++i;
            int j = i;
            int temp_num = 0;
            while(j < n && expression[j] >='0' && expression[j] <= '9') ++j;
            temp_num = std::stoi(expression.substr(i, j - i));
            int temp_den = 1;
            if(expression[j] == '/'){
                ++j;
                i = j;
                while(j < n && expression[j] >= '0' && expression[j] <= '9') ++j;
                temp_den = std::stoi(expression.substr(i, j - i));
            }
            i = j - 1;
            num = sign * temp_num * den + num * temp_den;
            den *= temp_den;
        }
        int gcd = std::gcd(std::abs(num), std::abs(den));
        std::string res = std::to_string(num / gcd);
        res += '/' + std::to_string(den / gcd);
        return res;
    }
};
