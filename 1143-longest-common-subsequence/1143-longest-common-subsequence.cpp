// optimal approach bottom up 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         int m= text1.size();
        int  n = text2.size();
        vector<vector<int>>t(m+1,vector<int> (n+1));
        //first row and first column will be zero 
        if (m == 0 || n == 0){
            return 0;
        }
        for(int row = 0 ; row < m+1;row++){
            t[row][0] = 0;
        }
        for(int col = 0 ; col <= n;col++){
            t[0][col] = 0;
        }

        for(int i = 1 ; i< m + 1; i++){
            for(int j = 1; j <n+1;j++){
                if (text1[i-1] == text2[j-1]){
                    t[i][j]= 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1 ][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
        
    }
};




// recursion + memo 
// class Solution {
// public:
//     int t[1001][1001];
//     int n  , m ;
//     int solve(string text1, string text2,int i , int j ){
//         if ( i >= n ||  j >= m){
//             return 0;
//         }
//         if (t[i][j]!= -1){
//             return t[i][j];
//         }
//         //take the string if match 
//         if (text1[i] == text2[j]){
//             return t[i][j]= 1 + solve(text1,text2 ,i+1,j+1);
//         }
//         // if not match then 2 cases we take from one string or not and same for another string 

//         else{
//             return t[i][j]  = max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         n = text1.size();
//         m = text2.size();
//         memset(t,-1,sizeof(t));
//         return solve(text1,text2,0,0);
        
//     }
// };


//recursion approach 


// class Solution {
// public:
//     int n  , m ;
//     int solve(string text1, string text2,int i , int j ){
//         if ( i >= n ||  j >= m){
//             return 0;
//         }
//         //take the string if match 
//         if (text1[i] == text2[j]){
//             return 1 + solve(text1,text2 ,i+1,j+1);
//         }
//         // if not match then 2 cases we take from one string or not and same for another string 

//         else{
//             return max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         n = text1.size();
//         m = text2.size();
//         return solve(text1,text2,0,0);
        
//     }
// };