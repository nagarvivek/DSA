//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // Function to reverse words in a given string.
    string reverseWords(string s) {
        string ans;
        stack<string> st;
        for (int i = 0; i < s.length(); i++) {
            string word = "";
            while (s[i] != '.' && i < s.length()) {
                word += s[i];
                i++;
            }
            st.push(word);
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += '.';
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends