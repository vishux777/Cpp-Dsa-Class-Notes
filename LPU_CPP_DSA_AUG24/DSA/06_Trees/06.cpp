//Binary Search Tree

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val){

    if(root==NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }

    return root;
}

Node* searchInBST(Node* root, int key){
    //base case
    if(root == NULL) return NULL;

    if(root->data == key) return root;

    //data > key
    if(root->data > key) return searchInBST(root->left, key);

    return searchInBST(root->right, key);
}
 
void inOrder(Node* root){
    if(root==NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    inOrder(root);
}