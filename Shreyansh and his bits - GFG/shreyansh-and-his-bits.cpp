//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long ncr(long n,long r) {
        if(r>n) return 0;
        long res = 1;
        for(int i=0;i<r;++i) {
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    long long count(long long x) {
        long long i=0;
        long long k=0,ans=0;
        while(x>0)
        {
            if(x&1) ans+=ncr(k,++i);
            k++;
            x=x>>1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends