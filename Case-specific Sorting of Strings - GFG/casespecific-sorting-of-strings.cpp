//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        string ans="";
        vector<char>mp1,mp2;
        for(int i=0;i<n;i++){
            if(s[i]>='a' and s[i]<='z') mp1.push_back(s[i]);
            else mp2.push_back(s[i]);
        }
        sort(mp1.begin(),mp1.end());
        sort(mp2.begin(),mp2.end());
        int k=0,l=0;
        for(int i=0;i<n;i++){
            if(s[i]>='a' and s[i]<='z'){
                ans+=mp1[k];
                k++;
            }
            else{
                ans+=mp2[l];
                l++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends