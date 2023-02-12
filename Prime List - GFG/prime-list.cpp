//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    Node *primeList(Node *head){
        vector<int>prime(10010,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<10010;i++){
            if(prime[i]){
                for(int j=2*i;j<10010;j+=i) prime[j]=false;
            }
        }
        
        Node* temp=head;
        while(temp!=NULL){
            if(!prime[temp->val]){
                int k=1;
                while(true){
                    if(prime[temp->val-k]){
                        temp->val-=k;
                        break;
                    }
                    if(prime[temp->val+k]){
                        temp->val+=k;
                        break;
                    }
                    k++;
                }
            }
            temp=temp->next;
        }
        return head;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends