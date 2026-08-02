class Solution {
public:
    // Check if we can make m  bouquets by day
    bool canMake(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {

            // Flower has bloomed
            if (bloom <= day) {
                flowers++;

                // We have k adjacent flowers
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;   // Flowers are used, start counting again
                }
            }
            else {
                // Adjacency breaks
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long totalFlowers = 1LL * m * k;

        // Impossible to make m bouquets
        if (totalFlowers > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, mid, m, k)) {
                ans = mid;          // Possible answer
                high = mid - 1;     // Try to find a smaller day
            }
            else {
                low = mid + 1;      // Need more days
            }
        }

        return ans;
    }
};