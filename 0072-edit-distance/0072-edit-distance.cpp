class Solution {
public:
int t[501][501];
    int solve(string &s1 , string &s2 , int m , int n){
        if ( m == 0 || n == 0){
            return m + n ;
        }

        if (t[m][n] != -1){
            return t[m][n];
        }
        if ( s1[m-1]== s2[n-1]){
            return t[m][n] = solve(s1,s2,m-1,n-1);

        }
         
            //if not match 
        int insertc = 1+ solve(s1,s2,m,n-1);
        int deleteC = 1+ solve(s1,s2,m-1,n);
        int replacec = 1 + solve(s1,s2,m-1,n-1);
        return  t[m][n] = min({insertc , deleteC , replacec});


        
        

    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        memset(t,-1,sizeof(t));
         return solve(word1,word2 ,  m ,  n );
    }
    
};