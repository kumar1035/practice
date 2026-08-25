class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> result;

        for (int i = 1; i <= nums.size() + 1; i++) {
            result.push_back(k * i);
        }
        for (int i = 0; i < result.size(); i++) {
            bool found = false;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == result[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return result[i];
            }
        }

        return -1;
    }
};