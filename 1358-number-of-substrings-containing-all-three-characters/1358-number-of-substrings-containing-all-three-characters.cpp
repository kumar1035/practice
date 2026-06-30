class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        int left = 0;
        int cnt =0;
        for(int right = 0 ; right < n ; right++){
            mp[s[right]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                cnt += (n-right);
                mp[s[left]]--;
                left++;
            }
        }
        return cnt;
        
    }
};