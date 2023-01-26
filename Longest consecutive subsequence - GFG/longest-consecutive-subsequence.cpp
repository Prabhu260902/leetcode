//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code her
      map<int,int>mp;
      sort(arr,arr+N);
      for(int i=0;i<N;i++){
          //cout<<arr[i]-1<<" "<<mp[arr[i]-1]<<endl;
          if(mp.find(arr[i]-1)!=mp.end()){
              
              mp[arr[i]]=mp[arr[i]-1]+1;
              
          }
          else mp[arr[i]]=1;
      }
      int ans=INT_MIN;
      for(auto i:mp){
          //cout<<i.first<<" "<<i.second<<endl;
          ans=max(ans,i.second);
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends