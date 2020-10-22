#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        data = d;
        left=NULL;
        right = NULL;
    }
};

node* build(){
    int d;
    cin>>d;

    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = build();
    root->right = build();
return root;
}

// bst 
node* bst(node* root, int d){
    if(root == NULL){
        return new node(d);
    }
    if(d < root->data){
        root->left = bst(root->left, d);
    }
    else if(d > root->data){
        root->right = bst(root->right, d);
    }
    else{
        return new node(d);
    }
return root;
}


void printPre(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}

int main(){
    node* root = build();
    bst(root, 100);
    printPre(root);
}