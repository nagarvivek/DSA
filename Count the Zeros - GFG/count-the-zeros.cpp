//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   int countZeroes(int arr[], int n) {
    int res = -1;
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == 0) {
            res = mid;
            end = mid - 1;
        } else if (arr[mid] == 1) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    if (res == -1)
        return 0; // No zeroes found
    else
        return n - res;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends