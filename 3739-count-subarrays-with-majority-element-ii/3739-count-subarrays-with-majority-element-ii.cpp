class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        // freq[i] stores how many times prefix sum (i - n) has occurred
        vector<int> freq(2 * n + 1, 0);

        int prefix = n;      // current prefix sum index (0 sum -> n)
        freq[prefix] = 1;

        long long ans = 0;
        long long valid = 0; // number of previous prefix sums < current prefix

        for (int i = 0; i < n; i++) {

            if (nums[i] == target) {

                // prefix sum increases by 1
                valid += freq[prefix];

                prefix++;

            } else {

                // prefix sum decreases by 1
                prefix--;

                valid -= freq[prefix];
            }

            // store current prefix
            freq[prefix]++;

            ans += valid;
        }

        return ans;
    }
};