class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;

        long long l = 1, h = x;

        while(l <= h) {
            long long mid = l + (h - l) / 2;
            long long sq = mid * mid;

            if(sq == x)
                return mid;

            if(sq > x)
                h = mid - 1;
            else
                l = mid + 1;
        }

        return h;
    }
};