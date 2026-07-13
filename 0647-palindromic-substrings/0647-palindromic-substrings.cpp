// Bottom up approach blue print for one length , 2 length and greater than 2 length 


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n,false));
        int cnt = 0;

        for(int len = 1 ; len<=n;len++){
            for(int i = 0 ; i+len-1<n;i++){
                int  j = i+len -1;
                //for one lenth 
                if (len ==1 ){
                    t[i][j] = true;
                } //for 2 length 
                else if (len == 2 ){
                    t[i][j] = (s[i] == s[j]);
                    
                 } // for more than 2 length 
                else{
                    t[i][j]= (s[i] == s[j] && t[i+1][j-1]);

                }
                if (t[i][j]== true){
                    cnt++;
                }


            }
        }
        return cnt;
    }
};



// recursion + memoization 
// class Solution {
// public:
//     int t[1001][1001];

//     bool check(string s , int i , int j ){
//         if ( i>j){
//             return true;
//         }
//         if (t[i][j]!= -1){
//             return t[i][j];
//         }
//         if (s[i] == s[j]){
//             return t[i][j]=check(s,i+1,j-1);
//         }
//         return t[i][j]=false;
//     }
//     int countSubstrings(string s) {
//         int n = s.size();
//         memset(t,-1,sizeof(t));
//         int cnt =0;
//         for(int i = 0;i<n;i++){
//             for(int j = i; j < n ; j++){
//                 if (check(s,i,j)){
//                     cnt++;
                    
//                 }
//             }
//         }
//         return cnt;
//     }
// };
// recursion approach 

// class Solution {
// public:
//     bool check(string s , int i , int j ){
//         if ( i>j){
//             return true;
//         }
//         if (s[i] == s[j]){
//             return check(s,i+1,j-1);
//         }
//         return false;
//     }
//     int countSubstrings(string s) {
//         int n = s.size();
//         int cnt =0;
//         for(int i = 0;i<n;i++){
//             for(int j = i; j < n ; j++){
//                 if (check(s,i,j)){
//                     cnt++;
                    
//                 }
//             }
//         }
//         return cnt;
//     }
// };