class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int N = nums.size();
        int n = N / 2;

        int n1 = n;  // left half
        int n2 = n;  // right half

        int S = accumulate(nums.begin(), nums.end(), 0);

        unordered_map<int, vector<int>> sumleft;
        unordered_map<int, vector<int>> sumright;

        // ---------------- LEFT HALF ----------------
        for (int mask = 0; mask < (1 << n1); mask++) {

            int s = 0;
            int cnt = 0;

            for (int i = 0; i < n1; i++) {

                if (mask & (1 << i)) {
                    s += nums[i];
                    cnt++;
                }
            }

            sumleft[cnt].push_back(s);
        }

        // ---------------- RIGHT HALF ----------------
        for (int mask = 0; mask < (1 << n2); mask++) {

            int s = 0;
            int cnt = 0;

            for (int i = 0; i < n2; i++) {

                if (mask & (1 << i)) {
                    s += nums[n1 + i];
                    cnt++;
                }
            }

            sumright[cnt].push_back(s);
        }

        // Sort right-half sums
        for (auto &it : sumright) {
            sort(it.second.begin(), it.second.end());
        }

        int ans = INT_MAX;

        // We need exactly n elements in first array.
        // If we take k elements from left,
        // we need n-k elements from right.

        for (auto &it : sumleft) {

            int cntLeft = it.first;
            int cntRight = n - cntLeft;

            if (sumright.find(cntRight) == sumright.end())
                continue;

            for (int leftSum : it.second) {

                // We want:
                //
                // selectedSum ≈ S / 2
                //
                // selectedSum = leftSum + rightSum

                int target = S / 2 - leftSum;

                auto &right = sumright[cntRight];

                // Find first rightSum >= target
                auto pos = lower_bound(right.begin(), right.end(), target);

                // Candidate 1
                if (pos != right.end()) {

                    int selectedSum = leftSum + *pos;

                    int difference = abs(S - 2 * selectedSum);

                    ans = min(ans, difference);
                }

                // Candidate 2
                if (pos != right.begin()) {

                    --pos;

                    int selectedSum = leftSum + *pos;

                    int difference = abs(S - 2 * selectedSum);

                    ans = min(ans, difference);
                }
            }
        }

        return ans;
    }
};