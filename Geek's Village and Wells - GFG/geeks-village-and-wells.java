//{ Driver Code Starts
import java.util.*;
import java.io.*;

class Gfg {
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t=Integer.parseInt(in.readLine());
        while(t-->0){
            
            String s[]=in.readLine().trim().split(" ");
            int n=Integer.parseInt(s[0]);
            int m=Integer.parseInt(s[1]);
            char c[][]=new char[n][m];
            for(int i=0;i<n;i++){
                s=in.readLine().trim().split(" ");
                for(int j=0;j<m;j++){
                    c[i][j]=s[j].charAt(0);
                }
            }
            Solution ob=new Solution();
            int ans[][]=ob.chefAndWells(n, m, c);

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    out.print(ans[i][j]+" ");
                }
                out.println();
            }
        }
        out.close();
    }
}
// } Driver Code Ends

class Pair {
    int r;
    int c;
    int dis;
    Pair(int row, int col, int d) {
        this.r = row;
        this.c = col;
        this.dis = d;
    }
}
//User function Template for Java
class Solution
{
    public int[][] chefAndWells(int n,int m,char c[][])
    {
        int[][] distance = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(distance[i], Integer.MAX_VALUE);
        }

        Queue<Pair> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == 'W') {
                    q.add(new Pair(i, j, 0));
                }
            }
        }

        int[] dir1 = {1, -1, 0, 0};
        int[] dir2 = {0, 0, -1, 1};
        while (!q.isEmpty()) {
            int s = q.size();
            while (s-- > 0) {
                int x = q.peek().r;
                int y = q.peek().c;
                int dis = q.peek().dis;
                q.poll();
                for (int i = 0; i < 4; i++) {
                    int a = x + dir1[i];
                    int b = y + dir2[i];
                    if (a >= 0 && a < n && b >= 0 && b < m) {
                        if ((c[a][b] == 'H' || c[a][b] == '.') && distance[a][b] == Integer.MAX_VALUE) {
                            distance[a][b] = dis + 2;
                            q.add(new Pair(a, b, dis + 2));
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '.' || c[i][j] == 'N' || c[i][j] == 'W') {
                    distance[i][j] = 0;
                }
                if (distance[i][j] == Integer.MAX_VALUE) {
                    distance[i][j] = -1;
                }
            }
        }
        return distance;
    }
}