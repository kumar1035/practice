class Solution {
public:
   vector<vector<int>> directions ={{-1,0},{1,0},{0,-1},{0,1}};
   void dfs(vector<vector<char>>& board , int i , int j , vector<vector<bool>> & visited){
    int m = board.size();
    int n = board[0].size();
    visited[i][j] = true;
    for (auto &dir : directions){
        int ni = i + dir[0];
        int nj = j + dir[1];
        if(ni >=0 && ni<m &&  nj>=0 && nj<n &&  board[ni][nj]=='O' &&  !visited[ni][nj]){
             dfs(board,ni,nj,visited);

        }
}
   }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false) );

        // first row 
        for (int j = 0; j < n;j++){
            if(board[0][j] == 'O' && !visited[0][j]){
                dfs(board,0,j,visited);

            }
        }
        //last row 
        for(int j=0;j<n;j++)
        {
            if(board[m-1][j]=='O' && !visited[m-1][j])
                dfs(board,m-1,j,visited);
        }
        // FIRST COLUMN
          for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' && !visited[i][0])
                dfs(board,i,0,visited);
        }

        // Last Column
        for(int i=0;i<m;i++)
        {
            if(board[i][n-1]=='O' && !visited[i][n-1])
                dfs(board,i,n-1,visited);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !visited[i][j])
                    board[i][j]='X';
            }
        }

        
    }
};