class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = INT_MAX;
        vector<int> dp(n, INF);
        
        int left = 0;
        long long curSum = 0;
        int ans = INF;
        
        for (int right = 0; right < n; right++) {
            curSum += arr[right];
            while (curSum > target) {
                curSum -= arr[left];
                left++;
            }
            
            if (curSum == target) {
                int length = right - left + 1;
                if (left > 0 && dp[left - 1] < INF) {
                    ans = min(ans, dp[left - 1] + length);
                }
                dp[right] = length;
            }
            
            if (right > 0) {
                dp[right] = min(dp[right], dp[right - 1]);
            }
        }
        
        return ans == INF ? -1 : ans;
    }
};