//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:	
    int isRepeat(string s) {
        int n = s.size();
        
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                string repeated = s.substr(0, i);
                string reconstructed;
                
                for (int j = 0; j < n / i; j++) {
                    reconstructed += repeated;
                }
                
                if (reconstructed == s) {
                    return 1;
                }
            }
        }
        
        return 0;
    }
};



//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}
// } Driver Code Ends