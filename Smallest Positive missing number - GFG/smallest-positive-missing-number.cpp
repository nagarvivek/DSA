//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) {
    std::unordered_set<int> s;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            s.insert(arr[i]);
            ans = std::max(ans, arr[i]);
        }
    }

    for (int i = 1; i <= ans; i++) {
        if (s.find(i) == s.end()) {
            return i;
        }
    }

    return ans + 1;
}
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends