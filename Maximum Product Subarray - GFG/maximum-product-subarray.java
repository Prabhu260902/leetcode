//{ Driver Code Starts
import java.io.*;
import java.util.*;

  public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            String[] inputLine = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            System.out.println(new Solution().maxProduct(arr, n));
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to find maximum product subarray
    long maxProduct(int[] arr, int n) {
        // code her
        long ans = arr[0];
        long prev_max_product = arr[0];
        long prev_min_product = arr[0];
        for(int i = 1 ; i < n ; i++){
            long current_max_product = Math.max(arr[i] , 
                                       Math.max(prev_max_product*arr[i],prev_min_product*arr[i]));
            long current_min_product = Math.min(arr[i] , 
                                       Math.min(prev_max_product*arr[i],prev_min_product*arr[i])); 
            ans = Math.max(ans,current_max_product);
            prev_max_product = current_max_product;
            prev_min_product = current_min_product;
        }
        return ans;
    }
}