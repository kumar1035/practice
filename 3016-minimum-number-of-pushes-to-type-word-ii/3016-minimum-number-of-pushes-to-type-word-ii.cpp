class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26, 0);

        for (char c : word) {
            f[c - 'a']++;
        }

        sort(f.begin(), f.end());

        int ans = 0;
        int btn = 8;

        for (int i = 25; i >= 0; i--) {
            if (f[i] != 0) {
                ans += f[i] * (btn / 8);
                btn++;
            }
        }

        return ans;
    }
};