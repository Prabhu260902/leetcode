//{ Driver Code Starts
import java.util.Scanner;
import java.util.*;

class ArrayList_Collection
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T>0)
		{
			ArrayList<Integer> A = new ArrayList<Integer>();
			int q = sc.nextInt();
			
			while(q>0)
			{
				char c = sc.next().charAt(0);
				GfG g = new GfG();
				if(c == 'a')
				{
					int x = sc.nextInt();
					g.add_to_ArrayList(A,x);
				}
				
				if(c == 'b')
					g.sort_ArrayList_Asc(A);
					
				if(c == 'c')
					g.reverse_ArrayList(A);
					
				if(c == 'd')
					System.out.print(g.size_Of_ArrayList(A)+" ");
					
				if(c == 'e')
					g.print_ArrayList(A);
				
				if(c == 'f')
					g.sort_ArrayList_Desc(A);
				
			q--;
			}
		T--;
		System.out.println();
		}
	}
}
// } Driver Code Ends


/*You are required to complete below methods*/

class GfG
{
    /*inserts an element x at 
    the back of the ArrayList A */
    void add_to_ArrayList(ArrayList<Integer> A, int x)
    {
	// Your code here
	A.add(x);
    }	
	
    /*sort the ArrayList A in ascending order*/
    void sort_ArrayList_Asc(ArrayList<Integer> A)
    {
	// Your code here
	    Collections.sort(A);
    }
	
    /*reverses the ArrayList A*/
    void reverse_ArrayList(ArrayList<Integer> A)
    {
	// Your code here
	    Collections.reverse(A);
    }
	
    /*returns the size of the ArrayList A */
    int size_Of_ArrayList(ArrayList<Integer> A)
    {
	// Your code here
	    return A.size();
    }
	
    /*sorts the ArrayList A in descending order*/
    void sort_ArrayList_Desc(ArrayList<Integer> A)
    {
	// Your code here
	    Collections.sort(A,Collections.reverseOrder());
    }
	
    /*prints space separated 
    elements of ArrayList A*/
    void print_ArrayList(ArrayList<Integer> A)
    {
        // Your code here
        for(int i:A) System.out.print(i+" ");
    }
}
