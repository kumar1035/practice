class Solution {
public:
    int m;
    int n ;
    int t[201][201];
    int solve(int i , int j){
        if ( i == m-1 && j == n-1){
            return 1;
        }
        if (t[i][j]!= -1){
            return t[i][j];
        }
        if ( i<0 |  i>= m || j <0 || j >= n){
            return 0;
        }
        int right = solve(i,j+1);
        int down = solve( i+1,j);
        return  t[i][j]= right + down;
    }
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        memset(t,-1,sizeof(t));
        return solve(0,0);
        
    }
};

// recursion approach 

// class Solution {
// public:
//     int m;
//     int n ;
//     int solve(int i , int j){
//         if ( i == m-1 && j == n-1){
//             return 1;
//         }
//         if ( i<0 |  i>= m || j <0 || j >= n){
//             return 0;
//         }
//         int right = solve(i,j+1);
//         int down = solve( i+1,j);
//         return right + down;
//     }
//     int uniquePaths(int m, int n) {
//         this->m = m;
//         this->n = n;
//         return solve(0,0);
        
//     }
// };