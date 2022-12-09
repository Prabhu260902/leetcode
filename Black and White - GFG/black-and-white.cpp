//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    long long ans=0;
    for(int i=0;i<N;i++){
        
        for(int j=0;j<M;j++)
        {
            int n=N*M-1;
            if(i+2<N and j+1<M) n--;
            if(i+2<N and j-1>=0) n--;
            if(i-2>=0 and j+1<M) n--;
            if(i-2>=0 and j-1>=0) n--;
            if(j+2<M and i+1<N) n--;
            if(j+2<M and i-1>=0) n--;
            if(j-2>=0 and i+1<N) n--;
            if(j-2>=0 and i-1>=0) n--;
            ans+=n;
            ans=ans%1000000007;
        }
    }
    return ans%1000000007;
}