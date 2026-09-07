class Solution {
public:
    int MOD = 1e9 + 7;

    int distinctSubseqII(string s) {
        vector<long long> end(26, 0);
        long long total = 0;

        for(char c : s) {
            long long add = (total + 1) % MOD;

            total = (total + add - end[c - 'a'] + MOD) % MOD;

            end[c - 'a'] = add;
        }

        return total;
    }
};