class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> dp(n + 1, 0);
        dp[0] = startFuel;
        for (int k = 1; k <= n; ++k) {
            for (int i = k - 1; i >= 0 && dp[i] >= stations[k - 1][0]; --i) {
                dp[i + 1] = max(dp[i + 1], dp[i] + stations[k - 1][1]);
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (dp[i] >= target) return i;
        }
        return -1;
    }
};

