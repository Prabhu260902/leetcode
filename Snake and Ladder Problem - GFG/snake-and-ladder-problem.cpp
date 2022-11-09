//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void sol(vector<int>adj[],vector<int>&dis,int pos,int dice)
    {
        if(pos>=30)
        {
            dis[30]=min(dis[30],dice);
            return ;
        }
        dis[pos]=min(dice,dis[pos]);
        for(int i=1;i<=6;i++)
        {
            if(dis[pos+i]>dice+1 and adj[pos+i].size()!=0 and pos+6<=30)
            {
                dis[pos+i]=dice+1;
                sol(adj,dis,adj[pos+i][0],dice+1);
            }
        }
        if(pos+6>=30) sol(adj,dis,30,dice+1);
        else sol(adj,dis,pos+6,dice+1);
    }
    int minThrow(int N, int arr[]){
        // code here
        vector<int>adj[31];
        for(int i=0;i<2*N;i+=2) adj[arr[i]].push_back(arr[i+1]);
        vector<int>dis(31,INT_MAX);
        int pos=1;
        int dice=0;
        dis[1]=0;
        sol(adj,dis,pos,dice);
        // for(int i=1;i<=30;i++)
        // {
        //     if(dis[i]==INT_MAX) cout<<-1<<" ";
        //     else cout<<dis[i]<<" ";
        //     if(i%10==0) cout<<endl;
        // }
        return dis[30];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends