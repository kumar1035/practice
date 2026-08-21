// Binary Search: Search for the smallest number mid such that at least k valid numbers exist up to mid.
// Count Multiples: For every subset of coins, calculate its LCM and count how many numbers up to mid are divisible by that LCM.
// Inclusion-Exclusion: Add counts for odd-sized subsets and subtract counts for even-sized subsets to avoid double-counting common multiples.
// Narrow the Search: If the count is >= k, store mid and search left; otherwise, search right. The final result is the kth smallest number

class Solution {
public:
    typedef long long ll;

    ll countSmaller(ll mid, vector<int>& coins) { 
        ll correctedCount = 0;
        int n = coins.size();

        for(int expressions = 1; expressions <= (1 << n) - 1; expressions++) {
            ll lcm = 0;
            ll order = 0;

            for(int i = 0; i < n; i++) {
                if(expressions & (1 << i)) {
                    order++;

                    if(lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }

            if(order % 2 == 0) {
                correctedCount -= mid / lcm;
            } else {
                correctedCount += mid / lcm;
            }
        }

        return correctedCount;
    }

    ll findKthSmallest(vector<int>& coins, int k) {
        ll result = -1;

        ll l = 1;
        ll r = (ll)(*max_element(begin(coins), end(coins))) * k;

        while(l <= r) {
            ll mid = l + (r - l) / 2;

            if(countSmaller(mid, coins) >= k) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};