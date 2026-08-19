
// recursion approach (but failed now memoized )
class Solution {
public:
    int m, n;
    int dp[1001][1001];


    int solve(int i, int j, string &s, string &t) {

        // Successfully formed t
        if (j == n)
            return 1;

        // s is exhausted but t is not
        if (i == m)
            return 0;

        if (dp[i][j] != -1){
            return dp[i][j];
        }

        if (s[i] == t[j]) {

            // Two possibilities

            // Take current character
            int take = solve(i + 1, j + 1, s, t);

            // Skip current character
            int skip = solve(i + 1, j, s, t);

            return dp[i][j] = take + skip;
        }

        // Characters don't match, only option is to skip
        return dp[i][j]=solve(i + 1, j, s, t);
    }

    int numDistinct(string s, string t) {
        m = s.size();
        n = t.size();
        memset(dp,-1,sizeof(dp));

        return solve(0, 0, s, t);
    }
};



// // recursion approach (but failed now memoized )
// class Solution {
// public:
//     int m, n;

//     int solve(int i, int j, string &s, string &t) {

//         // Successfully formed t
//         if (j == n)
//             return 1;

//         // s is exhausted but t is not
//         if (i == m)
//             return 0;

//         if (s[i] == t[j]) {

//             // Two possibilities

//             // Take current character
//             int take = solve(i + 1, j + 1, s, t);

//             // Skip current character
//             int skip = solve(i + 1, j, s, t);

//             return take + skip;
//         }

//         // Characters don't match, only option is to skip
//         return solve(i + 1, j, s, t);
//     }

//     int numDistinct(string s, string t) {
//         m = s.size();
//         n = t.size();

//         return solve(0, 0, s, t);
//     }
// };