//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	bool check_elements(int arr[], int n, int A, int B) {
    int* check = new int[B - A + 1]{0};
    
    for (int i = 0; i < n; i++) {
        if (arr[i] >= A && arr[i] <= B) {
            check[arr[i] - A] = 1;
        }
    }
    
    for (int i = 0; i < B - A + 1; i++) {
        if (check[i] == 0)
            return false;
    }
    
    delete[] check; // Deallocate the dynamically allocated array
    
    return true;
}



		 

};
	

//{ Driver Code Starts.


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,A,B;
		cin>>n>>A>>B;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];

        

        Solution ob;
        if (ob.check_elements(a, n, A, B))
			cout << "Yes";
		else
			cout << "No";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}







// } Driver Code Ends