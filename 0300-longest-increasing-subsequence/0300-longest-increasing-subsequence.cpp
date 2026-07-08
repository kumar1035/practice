// class Solution {
// public:
//     int n;

//     int solve(vector<int>& nums, int i, int prev) {
//         if (i >= n) {
//             return 0;
//         }

//         int take = 0;

//         // when the previous element is smaller than current element then take otherwise skip
//         if (prev == -1 || nums[prev] < nums[i]) {
//             take = 1 + solve(nums, i + 1, i);
//         }

//         int skip = solve(nums, i + 1, prev);

//         return max(take, skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         n = nums.size();
//         return solve(nums, 0, -1);
//     }
// };

//recursion + memoization 
// class Solution {
// public:
//     int n;
//     int t[2501][2501];

//     int solve(vector<int>& nums, int i, int prev) {
//         if (i >= n) {
//             return 0;
//         }
//         if (prev != -1 && t[i][prev] != -1){
//             return t[i][prev];
//         }

//         int take = 0;

//         // when the previous element is smaller than current element then take otherwise skip
//         if (prev == -1 || nums[prev] < nums[i]) {
//             take = 1 + solve(nums, i + 1, i);
//         }

//         int skip = solve(nums, i + 1, prev);
//         if (prev !=-1){
//             t[i][prev] = max(take,skip);
//         }

//         return  max(take, skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         n = nums.size();
//         memset(t,-1,sizeof(t));
//         return solve(nums, 0, -1);
//     }
// };


//bottom up approach 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, 1);

        // t[i] = LIS ending at ith index

        int maxLIS = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (nums[j] < nums[i]) {

                    t[i] = max(t[i], t[j] + 1);

                    maxLIS = max(maxLIS, t[i]);
                }
            }
        }

        return maxLIS;
    }
};