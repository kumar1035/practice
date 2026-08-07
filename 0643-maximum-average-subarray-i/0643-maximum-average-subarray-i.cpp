class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int sum = 0;
        int mx = INT_MIN;

        while (r < nums.size()) {
            sum += nums[r];

            if (r - l + 1 == k) {
                mx = max(mx, sum);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        return (double)mx / k;
    }
};