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
    
    printPre(root);
    return 0;
}