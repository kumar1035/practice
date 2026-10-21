class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n <= 0) return 0;

        vector<int> dp(n + 1, 0);
        dp[1] = nums[start];

        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1],nums[start + i - 1] + dp[i - 2]);
        }

        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int excludeLast = robRange(nums, 0, n - 2);
        int excludeFirst = robRange(nums, 1, n - 1);

        return max(excludeLast, excludeFirst);
    }
};