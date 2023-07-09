//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  int i=0,j=0;
  string ans="";
  while(j<=src.size())
  {
      if(src[i]==src[j])
      {
          j++;
      }
      else
      {
          int count = j - i;
          ans.push_back(src[i]);
          ans.push_back('0' + count);
          i=j;
          j++;
      }
  }
  return ans;
}     
 
