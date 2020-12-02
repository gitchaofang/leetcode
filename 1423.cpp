class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = std::accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int right = cardPoints.size() - 1;
        int res = sum;
        for(int i = 0; i < k; ++i){
            sum += (cardPoints[right--] - cardPoints[k - i - 1]);
            res = std::max(res, sum);
        }    
        return res;
    }
};
