class Solution {
public:
    using int64 = long long;

    int64 LIMIT;

    int64 countWays(vector<int> &cnt) {
        int64 ans = 1;
        int used = 0;

        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= cnt[i]; j++) {
                used++;

                __int128 cur = (__int128)ans * used;
                cur /= j;

                if (cur >= LIMIT)
                    return LIMIT;

                ans = (int64)cur;
            }
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        LIMIT = k;

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k)
            return "";

        int len = 0;
        for (int x : half)
            len += x;

        string left = "";

        for (int pos = 0; pos < len; pos++) {

            for (int ch = 0; ch < 26; ch++) {

                if (half[ch] == 0)
                    continue;

                half[ch]--;

                int64 ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + ch));
                    break;
                }

                k -= ways;
                half[ch]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};