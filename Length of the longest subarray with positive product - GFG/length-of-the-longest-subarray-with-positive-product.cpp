//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int nCnt=0;
           int ans=0,sumArray=0;
           int a=-1,b=-1;
           for(int i=0;i<n;i++){
               sumArray++;
               if(arr[i]==0){
                   sumArray--;
                   if(nCnt&1){
                       int x=INT_MIN,y=INT_MIN,p=INT_MIN,q=INT_MIN;
                       if(a!=-1){
                           x=a-1;
                           y=sumArray-a;
                       }
                       if(b!=-1){
                           p=b-1;
                           q=sumArray-b;
                       }
                       ans=max(ans,max(x,max(y,max(p,q))));
                   }
                   else{
                       ans=max(ans,sumArray);
                   }
                   sumArray=0;
                   a=-1;
                   b=-1;
                   nCnt=0;
               }
               else if(arr[i]<0) 
               {
                   if(a==-1) a=sumArray;
                   else b=sumArray;
                   nCnt++;
               }
               
           }
           //cout<<sumArray<<" "<<a<<" "<<b<<" "<<nCnt<<" "<<ans<<endl;
           if(nCnt&1){
               int x=INT_MIN,y=INT_MIN,p=INT_MIN,q=INT_MIN;
               if(a!=-1){
                   x=a-1;
                   y=sumArray-a;
               }
               if(b!=-1){
                   p=b-1;
                   q=sumArray-b;
               }
               ans=max(ans,max(x,max(y,max(p,q))));
           }
           else{
               ans=max(ans,sumArray);
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends