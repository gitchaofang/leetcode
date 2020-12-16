class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool sign = true;
        if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) sign = false;
        int64_t num = std::abs(numerator);
        int64_t den = std::abs(denominator);
        std::string res =  std::to_string(num / den);
        num %= den;
        if(num != 0) res +='.';
        std::unordered_map<int,int>m;
        num *= 10;
        while(num != 0){
            if(m.find(num) != m.end()){
                res.insert(res.begin() + m[num],'(');
                res.push_back(')');
                break;
            }
            m[num] = res.size();
            if(num < den) res += '0';
            else res += std::to_string(num / den);
            num = num % den * 10; 
        }
        return sign == true ? res : '-' + res;
    }
};
