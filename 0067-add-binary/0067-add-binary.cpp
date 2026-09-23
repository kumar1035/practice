class Solution {
public:
    string addBinary(string a, string b) {
        int p1=a.size()-1,p2=b.size()-1;
        int carry=0;
        string ans="";
        while(p1>=0 || p2>=0 ||carry>0)
        {
            int sum=carry;
            if(p1>=0)
            {
                sum+=a[p1]-'0';
                p1--;
            }
            if(p2>=0)
            {
                sum+=b[p2]-'0';
                p2--;
            }
            ans+=char(sum%2 +'0');
            carry=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};