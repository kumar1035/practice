class Solution {
public:
    int m, n;
    int t[501][501];

    int solve(string &s1, string &s2, int i, int j) {

        // Base cases
        if (i == m) {
            return n - j;   // Insert remaining characters
        }

        if (j == n) {
            return m - i;   // Delete remaining characters
        }

        // Memoization
        if (t[i][j] != -1) {
            return t[i][j];
        }

        // Characters match
        if (s1[i] == s2[j]) {
            return t[i][j] = solve(s1, s2, i + 1, j + 1);
        }

        // Three operations
        int insertC  = 1 + solve(s1, s2, i, j + 1);
        int deleteC  = 1 + solve(s1, s2, i + 1, j);
        int replaceC = 1 + solve(s1, s2, i + 1, j + 1);

        return t[i][j] = min({insertC, deleteC, replaceC});
    }

    int minDistance(string s1, string s2) {
        m = s1.length();
        n = s2.length();

        memset(t, -1, sizeof(t));

        return solve(s1, s2, 0, 0);
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