class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        result[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {

            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (d > result[row][col]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    int newCost = d + grid[nr][nc];

                    if (newCost < result[nr][nc]) {

                        result[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});
                    }
                }
            }
        }

        return result[m-1][n-1] < health;
    }
};