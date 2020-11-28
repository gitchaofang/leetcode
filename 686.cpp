class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        std::string str("");
        int rpt = 0;
        while(str.size() < b.size()){
            ++rpt;
            str += a;
            if(str.find(b) != std::string::npos) return  rpt;
        }  
        str += a;
        if(str.find(b) == std::string::npos) return -1;
        return rpt + 1;
    }
};
