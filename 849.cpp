class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int n = seats.size();
        for(int i = 0; i < n; ++i){
            if(seats[i] == 1) continue;
            int j = i;
            while(j < n && seats[j] == 0) ++j;
            if(i == 0 || j == n){
                if(j - i > res) res = j - i;
            }
            else if((j - i) % 2 == 0 && (j - i) / 2 > res) res = (j - i) / 2;
            else if((j - i) % 2 != 0 && (j - i) / 2 + 1 > res) res = (j - i) / 2 + 1;
            i = j - 1;
        }
        return res; 
    }
};
