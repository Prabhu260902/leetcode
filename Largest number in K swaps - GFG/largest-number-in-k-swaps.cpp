//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans = "-1";
    void recursion(string &str,int k,int ind){
        // cout << k << " " << str << endkl
        if(ans == "-1") ans = str;
        else ans = max(ans,str);
        if(k == 0 || ind >= str.size()){
            return;
            
        }
        vector<int>v;
        char ch = str[ind];
      for(int j = str.size()-1 ; j > ind ; j--){
          if(str[j] >= ch){
              ch = str[j];
          }
      }
      if(ch == str[ind]) recursion(str,k,ind+1);
      else{
          for(int j = ind+1 ; j < str.size() ; j++){
              if(str[j] == ch){
                  swap(str[ind],str[j]);
                  recursion(str,k-1,ind+1);
                  swap(str[ind],str[j]);
              }
          }
      }
    return;
      
        
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
      recursion(str,k,0);
      return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends