//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int r=1,l=-1;
        int i=0,j=0;
        char dir='r';
        while(true){
            if(matrix[i][j]==0){
                if(dir=='r'){
                    if(j+1>=matrix[0].size()) return {i,j};
                    else j=j+1;
                }
                else if(dir=='d'){
                    if(i+1>=matrix.size()) return {i,j};
                    else i=i+1;
                }
                else if(dir=='l'){
                    if(j-1<0) return {i,j};
                    else j=j-1;
                }
                else if(dir=='u'){
                    if(i-1<0) return {i,j};
                    else i=i-1;
                }
            }
            else{
                matrix[i][j]=0;
                if(dir=='r'){
                    dir='d';
                    if(i+1>=matrix.size()) return {i,j};
                    else i=i+1;
                }
                else if(dir=='u'){
                    dir='r';
                    if(j+1>=matrix[0].size()) return {i,j};
                    else j=j+1;
                }
                else if(dir=='d'){
                    dir='l';
                    if(j-1<0) return {i,j};
                    else j=j-1;
                }
                else if(dir=='l'){
                    dir='u';
                    if(i-1<0) return {i,j};
                    else i=i-1;
                }
            }
        }
        return {0,0};
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends