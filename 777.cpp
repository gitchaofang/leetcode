class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        if(end.size() != n) return false;
        int i = 0; 
        int j = 0;
        while(i < n && j < n){
            while(i < n && start[i] == 'X') ++i;
            while(j < n && end[j] == 'X') ++j;
            if(i == n && j == n) return true;
            if((i == n && j != n) || (j ==n && i != n) || start[i] != end[j]) return false;
            
            if((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
            ++i;
            ++j;
        }
        while(i < n){
            if(start[i++] != 'X') return false;
        }
        while(j < n){
            if(end[j++] != 'X') return false;
        }
        return true;
    }
};
