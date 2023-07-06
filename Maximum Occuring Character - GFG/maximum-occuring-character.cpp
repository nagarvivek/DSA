//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int ans = INT_MIN;
        int vivek;
       int arr[26]={0};
       for(int i=0;i<str.size();i++)
       {
           arr[str[i] - 'a']++;
       }
       for(int i=0;i<26;i++)
       {
           if(arr[i] > ans)
           {
               ans = arr[i];
               vivek = i;
           }
       }
       char c= vivek + 'a';
       return c;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends