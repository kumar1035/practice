class Solution {
public:
   typedef pair<int,pair<int,int>> p;
   vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        // it is using the dijkstra algorithm on 2d matrix 
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>> pq;

        //comparator lambda fucntion

        auto isSafe =[&](int x, int y ){
            return x >= 0 && x <m && y>= 0 && y <n ;
        };
        
        result[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff = pq.top().first;
            auto coord = pq.top().second;
            int x = coord.first;
            int y = coord.second;
            pq.pop();
            if (x == m-1 && y == n-1){
                return diff;
            }
            for(auto & dir: directions){
                int x_ = x+ dir[0];
                int y_ = y + dir[1];
                if (isSafe(x_ ,y_)){
                    int absdiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxdiff = max(absdiff , diff);


                    if (result[x_][y_]> maxdiff){
                        result[x_][y_] = maxdiff;
                        pq.push({maxdiff , {x_,y_}});
                    }

                }
            }
        }
        return result[m-1][n-1];


        
    }
};