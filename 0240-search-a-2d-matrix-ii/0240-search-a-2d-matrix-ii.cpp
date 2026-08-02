class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = 0;
        int c = cols - 1;

        while (r < rows && c >= 0) {

            if (matrix[r][c] == target)
                return true;

            if (matrix[r][c] > target)
                c--;        // Remove current column
            else
                r++;        // Remove current row
        }

        return false;
    }
};