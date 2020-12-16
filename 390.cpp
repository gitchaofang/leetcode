class Solution {
public:
    int lastRemaining(int n) {
        int remain = n;
        int base = 1;
        int step = 1;
        bool left_to_right = true;
        while(remain > 1){
            if(left_to_right || remain % 2 == 1) base += step;
            step *= 2;
            remain /= 2;
            left_to_right = !left_to_right;
        }
        return base;
    }
};
