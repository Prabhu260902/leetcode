//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      //code here
      stack<char>st,st1,st2,st3;
      long long ans1 = 0, ans2 = 0;
      for(auto it:S){
          if(it == 'r'){
              if(st.size()>0 and st.top() == 'p'){
                  ans1 += X;
                  st.pop();
              }
              else st.push(it);
          }
          else st.push(it);
      }
      while(!st.empty()){
          char it = st.top();
          st.pop();
          if(it == 'r'){
              if(st1.size()>0 and st1.top() == 'p'){
                  ans1 += Y;
                  st1.pop();
              }
              else st1.push(it);
          }
          else st1.push(it);
      }
      for(auto it:S){
          if(it == 'p'){
              if(st2.size()>0 and st2.top() == 'r'){
                  ans2 += Y;
                  st2.pop();
              }
              else st2.push(it);
          }
          else st2.push(it);
      }
      while(!st2.empty()){
          char it = st2.top();
          st2.pop();
          if(it == 'p'){
              if(st3.size()>0 and st3.top() == 'r'){
                  ans2 += X;
                  st3.pop();
              }
              else st3.push(it);
          }
          else st3.push(it);
      }
    //   cout << ans1 << " " << ans2 << endl;
      return max(ans1,ans2);
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends