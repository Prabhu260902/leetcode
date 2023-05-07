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
  //Your code here 
  string ans = "";
  char ch = src[0];
  int cnt = 1;
  for(int i = 1 ; i < src.size() ; i++){
      if(src[i] != ch){
          ans += ch;
          ans += to_string(cnt);
          cnt = 1;
          ch = src[i];
      }
      else cnt++;
  }
  ans += ch;
  ans += to_string(cnt);
  return ans;
  
}     
 
