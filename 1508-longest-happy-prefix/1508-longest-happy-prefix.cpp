class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        if(n < 2)
            return "";
        vector<int> lps(n,0);
        int len = 0,i = 1;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len - 1];
                }
            }
        }
        string ans = "";
        for(int i = 0;i < lps[n-1];i++){
            ans += s[i];
        }  
        return ans; 
        
    }
};