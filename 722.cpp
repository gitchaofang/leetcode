class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        std::vector<std::string> res;
        bool in_block = false;
        std::string line("");
        for(const std::string& str: source){
            for(int i = 0; i < str.size(); ++i){
                if(i == str.size() - 1 && !in_block) line += str[i];
                else if(in_block){
                    if(str[i] =='*' && str[i + 1] == '/'){
                        in_block = false;
                        ++i;
                    }
                }
                else if(str[i] == '/' && str[i + 1] == '/') break;
                else if (str[i] == '/' && str[i + 1] == '*'){ 
                    in_block = true;
                    ++i;
                }
                else line += str[i];
            }
            if (line != "" && !in_block){ 
                res.push_back(line);
                line = "";
            }
            
            
        }
        return res;
    }
};
