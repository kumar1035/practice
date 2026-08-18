class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int maxlen = 0; 
        int left = 0;
        for(int right = 0 ; right < n; right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxlen = max(maxlen , right - left +1);

        }
        return maxlen;
        
    }
};