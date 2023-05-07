//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict,string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		    cin>>s[i];
		
		string tt;
		cin>>tt;
		
		vector<string> res = findMatchedWords(s,tt);
        sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		    cout<<res[i]<<" ";
		cout<<endl;
		
	}
}
// } Driver Code Ends


/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
vector<string> findMatchedWords(vector<string> dict,string pattern)
{
       //Your code here
       vector<string>v;
       for(auto str : dict){
           map<char,char>mp;
           bool flag = true;
           if(str.size() == pattern.size()){
               for(int i = 0 ; i < str.size() ; i++){
                   if(mp.find(pattern[i]) != mp.end()){
                       char k = mp[pattern[i]];
                       if(k != str[i]){
                           flag = false;
                           break;
                       }
                   }
                   if(mp.find(str[i]) != mp.end()){
                       char k = mp[str[i]];
                       if(k != pattern[i]){
                           flag = false;
                           break;
                       }
                   }
                   mp[pattern[i]] = str[i];
                    mp[str[i]] = pattern[i];
                   
               }
               if(flag) v.push_back(str);
           }
       }
       return v;
}