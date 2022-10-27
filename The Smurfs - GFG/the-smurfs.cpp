//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int r=0,g=0,b=0;
        for(int i=0;i<n;i++) a[i]=='R' ? r+=1 : a[i]=='G' ? g+=1 : b+=1;
        if(r==n or g==n or b==n) return n;
        if((r%2 and b%2 and g%2) or (!(r%2) and !(b%2) and !(g%2))) return 2;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends