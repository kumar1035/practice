class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row= matrix.size();
        int cols = matrix[0].size();

        int low = 0 ;
        int high = row*cols - 1;
        while(low<= high){
            int mid = low + (high-low)/2;
            int element = matrix[mid / cols][mid % cols];
            if (element == target ){
                return true;
            }
            else if (element< target){
                low = mid +1;
            }
            else{
                high = mid -1 ;
            }
        }
        return false;
    }
};