class Solution {
public:
    int n;
    int countOverlap(vector<vector<int>>& A,vector<vector<int>>& B,int row,int col){
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int newrow = row+i;
                int newcol = col+j;
                if(newrow<0 || newrow>=n || newcol<0 || newcol>=n)
                    continue;
                if(A[i][j]==1 && B[newrow][newcol]==1){
                    count++;
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        n = A.size();
        int ans = 0;
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                int count = countOverlap(A,B,i,j);
                ans = max(ans,count);
            }
        }
        return ans;
    }
};