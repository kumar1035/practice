class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> t(n, vector<int>(n));

        // Base case
        for (int j = 0; j < n; j++)
            t[0][j] = matrix[0][j];

        // Fill DP table
        for (int i = 1; i < n; i++) {

            for (int j = 0; j < n; j++) {

                int up = t[i - 1][j];

                int leftDiagonal = (j > 0)
                    ? t[i - 1][j - 1]
                    : INT_MAX;

                int rightDiagonal = (j < n - 1)
                    ? t[i - 1][j + 1]
                    : INT_MAX;

                t[i][j] = matrix[i][j] +
                          min({up, leftDiagonal, rightDiagonal});
            }
        }

        int ans = INT_MAX;

        // Minimum value in last row
        for (int j = 0; j < n; j++)
            ans = min(ans, t[n - 1][j]);

        return ans;
    }
};



// recursion + memoization 
// class Solution {
// public:
//     int n;
//     int t[101][101];

//     int solve(vector<vector<int>>& matrix, int row, int col) {

//         if (col < 0 || col >= n)
//             return 1e9;

//         if (row == n - 1)
//             return matrix[row][col];

//         if (t[row][col] != -1)
//             return t[row][col];

//         int down = solve(matrix, row + 1, col);
//         int leftDiagonal = solve(matrix, row + 1, col - 1);
//         int rightDiagonal = solve(matrix, row + 1, col + 1);

//         return t[row][col] =
//             matrix[row][col] +
//             min({down, leftDiagonal, rightDiagonal});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {

//         n = matrix.size();

//         memset(t, -1, sizeof(t));

//         int ans = INT_MAX;

//         for (int col = 0; col < n; col++) {
//             ans = min(ans, solve(matrix, 0, col));
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int n;

//     int solve(vector<vector<int>>& matrix, int row, int col) {

//         // Invalid column
//         if (col < 0 || col >= n)
//             return 1e9;

//         // Last row
//         if (row == n - 1)
//             return matrix[row][col];

//         int down = solve(matrix, row + 1, col);
//         int leftDiagonal = solve(matrix, row + 1, col - 1);
//         int rightDiagonal = solve(matrix, row + 1, col + 1);

//         return matrix[row][col] + min({down, leftDiagonal, rightDiagonal});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {

//         n = matrix.size();

//         int ans = INT_MAX;

//         // Start from every column of first row
//         for (int col = 0; col < n; col++) {
//             ans = min(ans, solve(matrix, 0, col));
//         }

//         return ans;
//     }
// };