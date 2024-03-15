#include <bits/stdc++.h>
using namespace std;

struct Node{//Difference between class and structures
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
//Building a BT when inorder and preorder traversal is given:

Node* buildTree(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    //When static is used within a function to declare a variable, it makes the variable local to the function but retains its value between function calls.

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);

    if(start==end){
        return node;
    }
    int pos= search(inorder,start,end,curr);
    node->left= buildTree(preorder,inorder,start,pos-1);
    node->right= buildTree(preorder,inorder, pos+1,end);
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    //Logic: Traverse through preorder and check their position in inorder
    /*Algorithm: 
    1. Pick element from preorder &create a node
    2. Increment preorder idx
    3. Search for picked element's pos in inorder
    4. Call to build subtree from inorder's 0 to pos-1
    5. Call to build right subtree from inorder pos+1 to n
    6. Return the node*/

    int preorder[] = {1,2,4,3,5};
    int inorder[]= {4,2,1,5,3};

    Node* root = buildTree(preorder,inorder,0,4);
    inorderPrint(root);

    return 0;
}