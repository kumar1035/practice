// Bottom up approach 


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>t(m , vector<int>(n) );
        t[0][0]= 0;
        if(m ==1 && n ==1){   // assuming source to detination should be 1 
            return 1;
        }
        for(int col = 1; col < n ; col++){
            t[0][col] = 1;
        }

        //fill 0th row with 1
        for(int row = 1; row <m ; row++){
            t[row][0]= 1;
        }

        for(int i = 1 ; i<m;i++){
            for(int j = 1 ;  j < n ; j++){
                t[i][j]= t[i-1][j]+ t[i][j-1];  //right + down
            }
        }
        return t[m-1][n-1];
        
    }
};



// recursion + memoization 
// class Solution {
// public:
//     int m;
//     int n ;
//     int t[201][201];
//     int solve(int i , int j){
//         if ( i == m-1 && j == n-1){
//             return 1;
//         }
//         if (t[i][j]!= -1){
//             return t[i][j];
//         }
//         if ( i<0 |  i>= m || j <0 || j >= n){
//             return 0;
//         }
//         int right = solve(i,j+1);
//         int down = solve( i+1,j);
//         return  t[i][j]= right + down;
//     }
//     int uniquePaths(int m, int n) {
//         this->m = m;
//         this->n = n;
//         memset(t,-1,sizeof(t));
//         return solve(0,0);
        
//     }
// };

// recursion approach 

// class Solution {
// public:
//     int m;
//     int n ;
//     int solve(int i , int j){
    //     if ( i == m-1 && j == n-1){
    //         return 1;
    //     }
    //     if ( i<0 ||  i>= m || j <0 || j >= n){
    //         return 0;
    //     }
    //     int right = solve(i,j+1);
    //     int down = solve( i+1,j);
    //     return right + down;
    // }
//     int uniquePaths(int m, int n) {
//         this->m = m;
//         this->n = n;
//         return solve(0,0);
        
//     }
// };