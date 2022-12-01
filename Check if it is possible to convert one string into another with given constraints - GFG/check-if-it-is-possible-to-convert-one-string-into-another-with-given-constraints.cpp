//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     string reduce(string s1)

    {

        string temp="";

        for(int i=0;i<s1.size();i++)

            if(s1[i]!='#')

                temp+=s1[i];

        return temp;

    }

    int isItPossible(string s1, string s2, int M, int N) {

        if(reduce(s1)!=reduce(s2))return 0;

        int c=0;

       for(int i=s1.size()-1;0<=i;i--){

           if(s1[i]=='A')c++;

           if(s2[i]=='A')c--;

           if(0>c)return 0;

       }

       c=0;

       for(int i=0;i<s1.size();i++){

           if(s1[i]=='B')c++;

           if(s2[i]=='B')c--;

           if(0>c)return 0;

       }

       return 1;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends