class Solution {
public:
    int m, n;
    int dp[2001][2001];

    bool solve(int i, int j, string &s, string &p) {

        // Both string and pattern are exhausted
        if (i == m && j == n)
            return true;

        // Pattern exhausted but string remains
        if (j == n)
            return false;

        // String exhausted
        if (i == m) {
            while (j < n) {
                if (p[j] != '*')
                    return false;
                j++;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match or '?'
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i + 1, j + 1, s, p);

        // '*'
        if (p[j] == '*') {

            // Match empty sequence
            bool empty = solve(i, j + 1, s, p);

            // Match one or more characters
            bool take = solve(i + 1, j, s, p);

            return dp[i][j] = (empty || take);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, s, p);
    }
};