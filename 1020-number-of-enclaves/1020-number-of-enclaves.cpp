class Solution {
public:
    vector<vector<int>> directions ={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& grid , int i , int j , vector<vector<bool>> & visited){
    int m = grid.size();
    int n = grid[0].size();
    visited[i][j] = true;
    for (auto &dir : directions){
        int ni = i + dir[0];
        int nj = j + dir[1];
        if(ni >=0 && ni<m &&  nj>=0 && nj<n &&  grid[ni][nj]==1 &&  !visited[ni][nj]){
             dfs(grid,ni,nj,visited);

        }
}
   }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false) );
        // first row 
        for (int j = 0; j < n;j++){
            if(grid[0][j] == 1 && !visited[0][j]){
                dfs(grid,0,j,visited);

            }
        }
        //last row 
        for(int j=0;j<n;j++)
        {
            if(grid[m-1][j]==1 && !visited[m-1][j])
                dfs(grid,m-1,j,visited);
        }
        // FIRST COLUMN
          for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1 && !visited[i][0])
                dfs(grid,i,0,visited);
        }

        // Last Column
        for(int i=0;i<m;i++)
        {
            if(grid[i][n-1]==1 && !visited[i][n-1])
                dfs(grid,i,n-1,visited);
        }
         int count = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                    count++;
            }
        }

        return count;
        
    }
};