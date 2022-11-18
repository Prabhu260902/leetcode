//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        while(t-- > 0)
        {
            String S = in.next();
            int N = in.nextInt();
            
            Solution ob = new Solution();
            ob.printIntString(S,N);
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution{
    static void printIntString(String S,int N){
        // code here
        System.out.println("The input string :"+S);
        System.out.println("The input integer :"+N);
    }
}