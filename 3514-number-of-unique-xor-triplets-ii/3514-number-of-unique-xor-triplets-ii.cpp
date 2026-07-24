class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXXOR = 2048;

        // Remove duplicates since the same index can be reused.
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> vals(st.begin(), st.end());

        vector<vector<bool>> dp(4, vector<bool>(MAXXOR, false));
        dp[0][0] = true;

        // Pick exactly 3 values (repetition allowed)
        for (int cnt = 1; cnt <= 3; cnt++) {
            for (int x = 0; x < MAXXOR; x++) {
                if (!dp[cnt - 1][x]) continue;

                for (int v : vals) {
                    dp[cnt][x ^ v] = true;
                }
            }
        }

        int ans = 0;
        for (int x = 0; x < MAXXOR; x++) {
            if (dp[3][x]) ans++;
        }

        return ans;
    }
};