// bottom approach 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

        // Base case
        t[0][0] = grid[0][0];

        // Fill first row
        for (int col = 1; col < n; col++) {
            t[0][col] = grid[0][col] + t[0][col - 1];
        }

        // Fill first column
        for (int row = 1; row < m; row++) {
            t[row][0] = grid[row][0] + t[row - 1][0];
        }

        // Fill the remaining cells
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                t[i][j] = grid[i][j] + min(t[i - 1][j], t[i][j - 1]);
            }
        }

        return t[m - 1][n - 1];
    }
};

// recursion + memoization 

// class Solution {
// public:
//     int m, n;
//     int t[201][201];

//     int solve(vector<vector<int>>& grid, int row, int col) {
//         if (row == m - 1 && col == n - 1) {
//             return grid[row][col];
//         }
//         if (t[row][col]!=-1){
//             return t[row][col];
//         }


//         if (row == m - 1) {      // Can only move right
//             return  t[row][col] = grid[row][col] + solve(grid, row, col + 1);
//         }
//         else if (col == n - 1) { // Can only move down
//             return  t[row][col] = grid[row][col] + solve(grid, row + 1, col);
//         }
//         else {
//             return t[row][col] = grid[row][col] +min(solve(grid, row, col + 1),solve(grid, row + 1, col));
//         }
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         memset(t,-1,sizeof(t));

//         return solve(grid, 0, 0);
//     }
// };

// recursion approach 

// class Solution {
// public:
//     int m, n;

//     int solve(vector<vector<int>>& grid, int row, int col) {
//         if (row == m - 1 && col == n - 1) {
//             return grid[row][col];
//         }

//         if (row == m - 1) {      // Can only move right
//             return grid[row][col] + solve(grid, row, col + 1);
//         }
//         else if (col == n - 1) { // Can only move down
//             return grid[row][col] + solve(grid, row + 1, col);
//         }
//         else {
//             return grid[row][col] +min(solve(grid, row, col + 1),solve(grid, row + 1, col));
//         }
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         return solve(grid, 0, 0);
//     }
// };