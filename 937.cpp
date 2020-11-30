class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        int pos = n - 1;
        for(int i = n - 1; i >= 0; --i){
            int c = logs[i][logs[i].find(' ') + 1];
            if(c >= '0' && c <= '9') swap(logs[i], logs[pos--]);
        }
        auto cmp = [](const std::string& str1, const std::string& str2){
            int pos1 = str1.find(' ');
            int pos2 = str2.find(' ');
            std::string head1 = str1.substr(0,pos1);
            std::string tail1 = str1.substr(pos1+1);
            std::string head2 = str2.substr(0,pos2);
            std::string tail2 = str2.substr(pos2+1);
            return (tail1 == tail2) ? head1 < head2 : tail1 < tail2; 
        };
        std::sort(logs.begin(), logs.begin() + pos + 1, cmp);
        return logs;
    }
};
