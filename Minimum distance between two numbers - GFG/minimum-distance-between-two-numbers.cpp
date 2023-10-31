//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
       int index1 = -1;
       int index2 = -1;
       int mini = INT_MAX;
       for(int i=0;i<n;i++)
       {
           if(a[i]==x)
           {
               index1 = i;
           }
           
           if(a[i]==y)
           {
               index2 = i;
           }
           
           if(index1 > -1 and index2 > -1)
           {
               int temp  = abs(index2 - index1);
               mini = min (temp , mini); 
           }
       }
       if(index1 ==-1 or index2 ==-1)
       {
           return -1;
       }
       return mini;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends