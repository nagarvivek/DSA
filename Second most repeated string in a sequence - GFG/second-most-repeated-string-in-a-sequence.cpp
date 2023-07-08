//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
          unordered_map<string, int> mp;
        
        for(int i = 0; i < n;i++){
            mp[arr[i]]++;
        }
        int fir = INT_MIN;
        int sec = INT_MIN;
        
        for(auto it : mp){
            if(it.second > fir){
                sec = fir;
                fir = it.second;
            }
            else if(it.second > sec && it.second != fir){
                sec  = it.second;
            }
        }
        
        for(auto it: mp){
            if(it.second == sec){
                return it.first;
            }
        }
        return "";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends