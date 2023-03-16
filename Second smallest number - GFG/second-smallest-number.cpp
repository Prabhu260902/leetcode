//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        string a = "-1";
        if(S >= 9*D) return a;
        int k = D,x=D-1;
        S-=1;
        
        // cout << S << " " << 9*D << endl;
        
        
        string s = "1";
        s+=string(D-1,'0');
        D--;
        while(S>0){
            if(S>=9){
                S-=9;
                s[D] = '9';
                x = D;
                D--;
            } 
            else{
                int p = s[D]-'0';
                p+=S;
                S=0;
                s[D] = p+'0';
                D--;
            }
        }
        // cout << s <<endl;
        s[x]--;
        s[x-1]++;
        return s;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends