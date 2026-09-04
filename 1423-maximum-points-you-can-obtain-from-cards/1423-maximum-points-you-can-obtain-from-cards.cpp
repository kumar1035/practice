class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int windowSize = n - k;

        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += cardPoints[i];
        }

        // If k == n, we take all cards
        if (windowSize == 0) {
            return totalSum;
        }
        int windowSum = 0;

        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minSum = windowSum;
        int left = 0;

        for (int right = windowSize; right < n; right++) {

            windowSum += cardPoints[right];
            windowSum -= cardPoints[left];
            left++;
            minSum = min(minSum, windowSum);
        }

        return totalSum - minSum;
    }
};