class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), MOD = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> cnt(n, vector<int>(n, 0));

        dp[n - 1][n - 1] = 0;
        cnt[n - 1][n - 1] = 1;

        int d[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};

        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || dp[r][c] == -1) continue;

                for (auto& dir : d) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nc >= 0 && board[nr][nc] != 'X') {
                        int v = (board[nr][nc] == 'E') ? 0 : (board[nr][nc] - '0');
                        int s = dp[r][c] + v;

                        if (s > dp[nr][nc]) {
                            dp[nr][nc] = s;
                            cnt[nr][nc] = cnt[r][c];
                        } else if (s == dp[nr][nc]) {
                            cnt[nr][nc] = (cnt[nr][nc] + cnt[r][c]) % MOD;
                        }
                    }
                }
            }
        }

        if (dp[0][0] == -1) return {0, 0};
        return {dp[0][0], cnt[0][0]};
    }
};