class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& piles) {

        if (i == j)
            return piles[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int takeLeft = piles[i] - solve(i + 1, j, piles);

        int takeRight = piles[j] - solve(i, j - 1, piles);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, piles) > 0;
    }
};