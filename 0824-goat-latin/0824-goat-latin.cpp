class Solution {
public:
  string toGoatLatin(string sentence) {
    deque<string>a;
    string ans="";
    string trill="";
    string s;
    int cnt=0;
    for(int i=0;i<sentence.size()+1;i++)
    {if(sentence[i]!=' ')
      {
    s+=sentence[i];
      }else 
      {
        cnt++;
        a.push_back(s);
        s="";
      }

    }
    s=s.substr(0,s.size()-1);
    a.push_back(s);
    for(auto it:a)
    {
        trill=trill+'a';
      if(it[0]=='a'||it[0]=='e'||it[0]=='i'||it[0]=='o'||it[0]=='u'||it[0]=='A'||it[0]=='E'||it[0]=='I'||it[0]=='O'||it[0]=='U')
      {
        it+="ma"+trill;
      }else
      {
        it=it.substr(1,it.size())+it[0]+"ma"+trill;
      }
      

   ans+=it+' ';
    }
      ans=ans.substr(0,ans.size()-1);
    return ans;
  }
};
