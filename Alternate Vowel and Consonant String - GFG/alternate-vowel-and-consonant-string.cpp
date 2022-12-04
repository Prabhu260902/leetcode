//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        // your code here
        int a=0,b=0;
        map<char,int>vo;
        map<char,int>cons;
        string ans="";
        for(auto i:S){
            if(i=='a' || i=='e' || i=='o' || i=='i' || i=='u'){
                vo[i]+=1;
                a+=1;
            }
            else
            {
                cons[i]+=1;
                b+=1;
            }
        }
        if(a==b+1 || a==b)
        {
            while(N--){
                if(vo.size()>0){
                    auto it=vo.begin();
                    ans+=it->first;
                    if(it->second==1) vo.erase(it->first);
                    else it->second-=1;
                }
                if(cons.size()>0){
                    auto it=cons.begin();
                    ans+=it->first;
                    if(it->second==1) cons.erase(it->first);
                    else it->second-=1;
                }
            }
            return ans;
        }
        else if(b==a+1)
        {
            while(N--){
                if(cons.size()>0){
                    auto it=cons.begin();
                    ans+=it->first;
                    if(it->second==1) cons.erase(it->first);
                    else it->second-=1;
                }
                if(vo.size()>0){
                    auto it=vo.begin();
                    ans+=it->first;
                    if(it->second==1) vo.erase(it->first);
                    else it->second-=1;
                }
            }
            return ans;
        }
        return "-1";
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends