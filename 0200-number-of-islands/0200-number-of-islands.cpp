class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;

        int n = grid[0].size();
        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    result++;
                }
            }
        }
        return result;
    }

private:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        // boundary check + water check
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;

        // mark visited land as water
        grid[i][j] = '0';

        // explore neighbors (up, down, left, right)
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
};
