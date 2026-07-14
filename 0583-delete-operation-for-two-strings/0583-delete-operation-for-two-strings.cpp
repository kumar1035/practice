class Solution {
public:
    int m, n;
    int t[501][501];

    int solve(int i, int j, string &word1, string &word2) {

        if(i == m)
            return n - j;

        if(j == n)
            return m - i;
        if (t[i][j] != -1){
            return t[i][j];

        }

        if(word1[i] == word2[j])
            return t[i][j] = solve(i + 1, j + 1, word1, word2);

        // Two possibilities

        int delete_word1 = 1 + solve(i + 1, j, word1, word2);

        int delete_word2 = 1 + solve(i, j + 1, word1, word2);

        return t[i][j]= min(delete_word1, delete_word2);
    }

    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();
        memset(t,-1,sizeof(t));

        return solve(0, 0, word1, word2);
    }
};