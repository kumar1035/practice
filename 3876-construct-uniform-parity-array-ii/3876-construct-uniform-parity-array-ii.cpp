class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = INT_MAX;

        for(int num : nums1) {
            minVal = min(minVal, num);
        }

        if(minVal & 1) {
            return true;
        }

        for(int num : nums1) {
            if(num & 1) {
                return false;
            }
        }

        return true;
    }
};