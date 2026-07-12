// recursion + memoization 

class Solution {
public:
    int t[501][501];

    int solve(string &s1, string &s2, int m, int n) {

        if (m == 0 || n == 0)
            return m + n;

        if (t[m][n] != -1)
            return t[m][n];

        if (s1[m - 1] == s2[n - 1])
            return t[m][n] = solve(s1, s2, m - 1, n - 1);

        int insertC  = 1 + solve(s1, s2, m, n - 1);
        int deleteC  = 1 + solve(s1, s2, m - 1, n);
        int replaceC = 1 + solve(s1, s2, m - 1, n - 1);

        return t[m][n] = min({insertC, deleteC, replaceC});
    }

    int minDistance(string word1, string word2) {

        memset(t, -1, sizeof(t));

        return solve(word1, word2, word1.length(), word2.length());
    }
};







// recursion approach 

// Time Complexity: O(3^(m+n)) (exponential due to overlapping subproblems)
// Space Complexity: O(m+n) (recursion stack)

// class Solution {
// public:
//     int m, n;

//     int solve(string &s1, string &s2, int i, int j) {

//         if (i == m) {
//             return n - j; // Insert remaining characters of s2
//         }
//         else if (j == n) {
//             return m - i; // Delete remaining characters of s1
//         }

//         if (s1[i] == s2[j]) {
//             return solve(s1, s2, i + 1, j + 1);
//         }
//         else {
//             int insertC  = 1 + solve(s1, s2, i, j + 1);
//             int deleteC  = 1 + solve(s1, s2, i + 1, j);
//             int replaceC = 1 + solve(s1, s2, i + 1, j + 1);

//             return min({insertC, deleteC, replaceC});
//         }
//     }

//     int minDistance(string s1, string s2) {
//         m = s1.length();
//         n = s2.length();

//         return solve(s1, s2, 0, 0);
//     }
// };