class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool all_zeros = true;
        int finalXor = 0;
        for (auto i : nums) {
            if (i) all_zeros = false;

            finalXor = finalXor ^ i;
        }

        if (all_zeros) return 0;

        if (finalXor) return nums.size();
        else return nums.size() - 1;
    }
};