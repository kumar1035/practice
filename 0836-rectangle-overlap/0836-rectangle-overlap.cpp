class Solution {
public:

    bool check(int a, int b, int c, int d) {
        return c < b && d > a;
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check overlap on X-axis
        bool xOverlap = check(rec1[0], rec1[2], rec2[0], rec2[2]);

        // Check overlap on Y-axis
        bool yOverlap = check(rec1[1], rec1[3], rec2[1], rec2[3]);

        return xOverlap && yOverlap;
    }
};