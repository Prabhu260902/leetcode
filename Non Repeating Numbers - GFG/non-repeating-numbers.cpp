//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int x = 0;
        vector<int>a,b,xx;
        for(auto it:nums){
            x = x^it;
        }
        int i = 0;
        while(true){
            if((x>>i)&1) break;
            i++;
        }
        for(auto it:nums){
            if((it>>i)&1) a.push_back(it);
            else b.push_back(it);
        }
        int A = 0,B = 0;
        for (auto it:a){
            // cout << A << " ";
            A=A^it;
        }
        // cout << endl;
        for (auto it:b){
            // cout << B << " ";
            B=B^it;
        }
        // cout << endl;
        if(A<B) return {A,B};
        return {B,A};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends