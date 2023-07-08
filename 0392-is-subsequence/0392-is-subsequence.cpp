class Solution {
public:
    bool isSubsequence(string s, string t) {
       int n = t.size();
       int i=0;
       int j=0;
       int count = s.size();
       while(n-- and count)
       {
           if(s[i]==t[j])
           {
               i++;
               j++;
               count--;
           }
            else
            {
                j++;
            }
       }
       if(count==0)
       return true;
       else
       return false; 
    }
};