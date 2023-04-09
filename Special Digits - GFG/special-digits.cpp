//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int a, int b, int c,int d,string str){
        // cout << c << " " << d << " " << str << endl;
        if(c == 0 || d == 0) return 1;
        if(c < 0 and d < 0) return 0;
        if(n == 0) return 0;
        int x = 0 ,y = 0;
        x = 0+solve(n-1,a,b,c-a,d-a,str+'a');
        y = 0+solve(n-1,a,b,c-b,d-b,str+'b');
        return x+y;
    }
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
        return solve(N,A,B,C,D,"");
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends