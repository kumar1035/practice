class Solution {
public:
    int n;
    pair<int,int> dp[2501][2501];
    bool vis[2501][2501];

    pair<int,int> solve(vector<int>& nums, int i, int prev) {
        if (i == n)
            return {0, 1};      // {length, count}

        if (vis[i][prev + 1])
            return dp[i][prev + 1];

        vis[i][prev + 1] = true;

        pair<int,int> take = {0, 0};

        if (prev == -1 || nums[prev] < nums[i]) {
            take = solve(nums, i + 1, i);
            take.first++;
        }

        pair<int,int> skip = solve(nums, i + 1, prev);

        if (take.first > skip.first)
            return dp[i][prev + 1] = take;

        if (skip.first > take.first)
            return dp[i][prev + 1] = skip;

        return dp[i][prev + 1] = {take.first, take.second + skip.second};
    }

    int findNumberOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(vis, false, sizeof(vis));

        return solve(nums, 0, -1).second;
    }
};