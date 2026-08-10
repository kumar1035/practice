class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // dp[i] = true means Alice can win with i stones

        for (int i = 1; i <= n; i++) {

            // Try every perfect square <= i
            for (int j = 1; j * j <= i; j++) {

                int square = j * j;

                // If after Alice's move Bob is in a losing state,
                // Alice wins.
                if (!dp[i - square]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};