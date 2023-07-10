//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string low = "";
        string up = "";
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='a' and str[i]<='z')
            {
                low.push_back(str[i]);
                str[i]='1';
            }
            else
            {
                up.push_back(str[i]);
                str[i]='0';
            }
        }
        sort(low.begin(),low.end());
        sort(up.begin(),up.end());
        int j=0;
        int  k=0;
        
        for(int i = 0;i<str.size();i++)
        {
            if(str[i]=='1')
            {
                str[i] = low[j++];
            }
            else
            {
                str[i] = up[k++];
            }
        }
        
        return str;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends