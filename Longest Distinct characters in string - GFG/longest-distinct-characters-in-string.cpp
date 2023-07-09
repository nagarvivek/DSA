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


int longestSubstrDistinctChars(string S) {
    int n = S.length(); // length of the string
    int maxLength = 0; // length of the longest substring
    unordered_set<char> distinctChars; // set to store distinct characters

    int left = 0; // left pointer
    int right = 0; // right pointer

    while (right < n) {
        // If the current character is not present in the set
        if (distinctChars.find(S[right]) == distinctChars.end()) {
            // Add the character to the set and move the right pointer
            distinctChars.insert(S[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        else {
            // If the current character is already present in the set
            // Remove the character at the left pointer from the set
            distinctChars.erase(S[left]);
            left++;
        }
    }

    return maxLength;
}