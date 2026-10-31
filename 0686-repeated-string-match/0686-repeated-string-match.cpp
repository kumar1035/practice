class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        string newstr = "";
        int count = 0;

        while (newstr.size() < b.size()) {
            newstr += a;
            count++;
        }

        if (newstr.find(b) != string::npos) {
            return count;
        }

        newstr += a;
        count++;

        if (newstr.find(b) != string::npos) {
            return count;
        }

        return -1;
    }
};