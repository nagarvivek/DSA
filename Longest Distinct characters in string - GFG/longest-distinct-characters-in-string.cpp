//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars(string s) {
    int count[26] = {0};
    int first = 0;
    int res = 0;
    int temp = 0;
    
    for (int second = 0; second < s.size(); second++) {
        count[s[second] - 'a']++;
        
        // Check if a character is repeated
        while (count[s[second] - 'a'] > 1) {
            count[s[first] - 'a']--;
            first++;
            temp--;
        }
        
        temp++;
        res = max(temp, res);
    }
    
    return res;
}
