//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int findK(int A[MAX][MAX], int n, int m, int k)
{
//Your code here
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>> dir = {{0,1} , {1,0} , {0,-1} , {-1,0}};
    int i = 0 , j = 0;
    int d = 0;
    for(int p = 1 ;p <= n*m ; p++){
        vis[i][j] = 1;
        k--;
        if(k == 0) return A[i][j];
        if( i + dir[d][0] >= n || j + dir[d][1] >= m || i + dir[d][0] < 0 || j + dir[d][1] < 0 ||
            vis[i + dir[d][0]][j + dir[d][1]] != 0){
            d = d + 1;
            if(d == 4) d = 0;
        }
        i = i + dir[d][0];
        j = j + dir[d][1];
    }
    return -1;
}

