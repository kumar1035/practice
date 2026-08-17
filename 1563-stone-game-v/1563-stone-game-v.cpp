class Solution {
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;

public:
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();

        prefix.resize(n);
        dp.assign(n, vector<int>(n, -1));

        prefix[0] = stoneValue[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i];
        }

        return solve(0, n - 1);
    }

private:
    int solve(int l, int r) {
        if (l == r) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int ans = INT_MIN;

        for (int i = l; i < r; i++) {
            int sum1 = getSum(l, i);
            int sum2 = getSum(i + 1, r);

            if (sum1 > sum2) {
                int temp = sum2 + solve(i + 1, r);
                ans = max(ans, temp);

            } else if (sum2 > sum1) {
                int temp = sum1 + solve(l, i);
                ans = max(ans, temp);

            } else {
                int temp = sum1 +
                    max(solve(l, i), solve(i + 1, r));

                ans = max(ans, temp);
            }
        }

        return dp[l][r] = ans;
    }

    int getSum(int i, int j) {
        return prefix[j] - (i > 0 ? prefix[i - 1] : 0);
    }
};