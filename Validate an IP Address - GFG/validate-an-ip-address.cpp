//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            int intTemp = 0;
            string temp="";
            int count=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='.')
                {
                    if(temp=="")return 0;
                    intTemp = stoi(temp);
                    if(intTemp > 255)return 0;
                    if(temp.size()>1 and temp[0]=='0')return 0;
                    temp="";
                    count++;
                    
                }
                else
                {
                    temp+=s[i];
                    if(!isdigit(s[i]))return 0;
                }
            }
                if(temp=="")return 0;
                if(intTemp>255)return 0;
                if(temp.size()>1 and temp[0]=='0')return 0;
                if(count!=3)return 0;
                return 1;
            }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends