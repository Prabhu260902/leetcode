//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
#include<bits/stdc++.h>
/*The function below returns an int denoting
the length of the longest palindrome list. */

int maxPalindrome(Node *head)
{
    //Your code here
    vector<int>s,t;
    int n = 0;
    while(head != NULL){
        n++;
        s.push_back(head->data);
        head = head -> next;
    }
    vector<vector<int>>dp(n,vector<int>(n,0));
    int len = -1;
    for(int diff = 0 ; diff < n ; diff++){
        for(int i = 0 , j = i+diff ; j < n ; i++,j++ ){
            if(i == j) dp[i][j] = 1;
            else{
                if(s[i] == s[j]){
                    if(diff == 1) dp[i][j] = 2;
                    else{
                        if(dp[i+1][j-1] > 0) dp[i][j] = 2 + dp[i+1][j-1];
                    }
                }
            }
            if(dp[i][j] > 0){
                if(j-i+1 > len){
                    len = j-i+1;
                }
            }
        }
    }
        return len;
}