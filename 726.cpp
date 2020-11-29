class Solution {
public:
    string countOfAtoms(string formula) {
        if(formula == "") return "";
        int n = formula.size();
        std::stack<std::pair<std::string,int>>st;
        for(int i = 0; i < n; ++i){
            if(formula[i] != '('){
                int j = i;
                while(j < n && formula[j] != '(') ++j;
                std::string str = formula.substr(i, j - i);
                st.push({str, 1});
                i = j - 1;
            }
            else{
                int cnt = 1;
                int j = i + 1;
                while(cnt != 0){
                    if(formula[j] == '(') ++cnt;
                    else if(formula[j] == ')') --cnt;
                    ++j;
                }
                std::string str = countOfAtoms(formula.substr(i + 1, j - i - 2));
                cnt = 0;
                while(j < n && formula[j] >= '0' && formula[j] <='9'){
                    cnt = cnt * 10 + (formula[j] - '0');
                    ++j;
                }
                if(cnt == 0) cnt = 1;
                st.push({str, cnt});
                i = j - 1;
            }
        }
        
        std::map<std::string, int> m;
        while(!st.empty()){
            std::string str = st.top().first;
            int rpt = st.top().second;
            st.pop();
            for(int i = 0; i < str.size(); ++i){
                int j = i + 1;
                while(j < str.size() && str[j] >= 'a' && str[j] <= 'z') ++j;
                std::string name = str.substr(i, j - i);
                int cnt = 0;
                while(j < str.size() && str[j] >= '0' && str[j] <= '9'){
                    cnt = cnt * 10 + (str[j] - '0'); 
                    ++j;
                }
                if(cnt == 0) cnt = 1;
                m[name] += cnt * rpt;
                i = j - 1;
            }
        }
        std::string res("");
        for(auto it = m.begin(); it != m.end(); ++it){
            if(it -> second == 1) res += (it -> first);
            else res += (it -> first + std::to_string(it -> second));
        }
        return res;
    }
};
