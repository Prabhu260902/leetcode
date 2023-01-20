//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      map<int,int,greater<int>>mp;
      for(int i=0;i<N;i++)
      {
          mp[Edge[i]]+=i;
      }
      int a=0,k=0;
      for(auto i:mp){
          if(i.first!=-1 and i.second>k){
              a=i.first;
              k=i.second;
          }
      }
      if(a==-1) return 0;
      return a;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends