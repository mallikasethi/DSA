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

node* bst(node* root, int d){
    if(root == NULL){
        return new node(d);
    }
    if(d < root->data){
         bst(root->left, d);
    }
    else if(d > root->data){
         bst(root->right, d);
         //works this way as well
    }
    else{
        return new node(d);
    }
return root;
}

// node* del(node* root, int key){
//    // first search
//    if(root == NULL){
//        return NULL;
//    }
//    if(key < root->data){
//     del(root->left, key);
//    }
//    else if(key > root->data){  
//     del(root->right, key);
//    }
    
  
// }


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
    root = bst(root,100);
    printPre(root);
    return 0;
}