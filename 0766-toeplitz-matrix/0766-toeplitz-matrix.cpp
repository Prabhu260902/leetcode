class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int b=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<matrix.size();i++)
        {
            int a=-1;
            int c=0;
            for(int j=i;j<matrix.size();j++)
            {
                if(j<n and c<m){
                    if(a==-1) a=matrix[j][c];
                    else if(a!=matrix[j][c]) return false;
                    //cout<<j<<" "<<c<<endl;
                    c++;
                }
            }
            //cout<<endl;
            b++;
        }
        int k=1;
        for(int i=1;i<matrix[0].size();i++)
        {
            int a=-1;
            int p=0;
            for(int j=i;j<matrix[0].size();j++)
            {
                if(p<n and j<m){
                    if(a==-1) a=matrix[p][j];
                    else if(a!=matrix[p][j]) return false;
                    //cout<<p<<" "<<j<<endl;
                    p++;
                }
            }
            //cout<<endl;
            k++;
        }
        return true;
    }
};