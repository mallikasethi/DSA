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

bool search(node* root, int d){
    if(root == NULL){
        return false;
    }
    if(root->data == d){
        return true;
    }
    search(root->left, d);
    search(root->right,d);
return false;
}

int main(){
    node* root = build();
    
    bool ans = search(root, 100);
    if(ans){
        cout<<"present";
    }
    else{
        cout<<"not present";
    }
   
    return 0;
}