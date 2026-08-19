class Solution {
public:

    int dp[1001][1001];

    int solve(int i, int j, string &str1, string &str2) {

        // Base cases
        if (i == 0)
            return j;

        if (j == 0)
            return i;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters are same
        if (str1[i - 1] == str2[j - 1]) {
            return dp[i][j] =
                1 + solve(i - 1, j - 1, str1, str2);
        }

        // Characters are different
        return dp[i][j] =
            1 + min(
                solve(i - 1, j, str1, str2),
                solve(i, j - 1, str1, str2)
            );
    }


    string shortestCommonSupersequence(string str1, string str2) {

        int m = str1.size();
        int n = str2.size();

        memset(dp, -1, sizeof(dp));

        // First calculate SCS length
        solve(m, n, str1, str2);

        // Now construct the actual SCS
        string res = "";

        int i = m;
        int j = n;

        while (i > 0 && j > 0) {

            // Same character -> take it once
            if (str1[i - 1] == str2[j - 1]) {

                res.push_back(str1[i - 1]);

                i--;
                j--;
            }

            // Different characters
            else {

                int option1 = solve(i - 1, j, str1, str2);
                int option2 = solve(i, j - 1, str1, str2);

                if (option1 < option2) {

                    // Take character from str1
                    res.push_back(str1[i - 1]);
                    i--;

                } else {

                    // Take character from str2
                    res.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        // Remaining characters of str1
        while (i > 0) {
            res.push_back(str1[i - 1]);
            i--;
        }

        // Remaining characters of str2
        while (j > 0) {
            res.push_back(str2[j - 1]);
            j--;
        }

        // We constructed it backwards
        reverse(res.begin(), res.end());

        return res;
    }
};