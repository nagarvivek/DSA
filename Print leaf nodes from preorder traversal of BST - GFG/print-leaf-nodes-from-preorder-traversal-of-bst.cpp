//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isLeaf(int pre[], int &i, int n,int min, int max,vector<int> &leafNodes)
{   
    if (i >= n)
        return false;
     
    if (pre[i] > min && pre[i] < max) {
        i++;
         
        bool left = isLeaf(pre, i, n, min, pre[i-1],leafNodes); //leftCall
        bool right = isLeaf(pre, i, n, pre[i-1], max,leafNodes); //rightCall
         
        if (!left && !right){
            leafNodes.push_back(pre[i-1]);   
        }
        return true;
    }
    return false;
}
  public:
    vector<int> leafNodes(int preOrder[],int n) {
        vector<int> leafNodes;
        int i=0;
        isLeaf(preOrder,i,n,INT_MIN,INT_MAX,leafNodes);
        return leafNodes;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends