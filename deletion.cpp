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
    }
    else{
        return new node(d);
    }
return root;
}


// node* deleteFromBST(node*root,int key){
// 	if(root==NULL){
// 		//key doesnt exist
// 		return root;
// 	}
// 	if(key<root->data){
// 		// search in left subtree
// 		 deleteFromBST(root->left,key);
//          // this will run an infinite loop since our root is the root node itself 
//          // and we are not return anything to it children so rather must be
//          // root->left = deleteFromBST(root->left,key);
// 		return root;
// 	}
// 	else if(key>root->data){
// 		// search in right subtree
// 	    deleteFromBST(root->right,key);
// 		return root;
// 	}
// 	else{
// 		//Key==root->data, key mil gyi!
// 		if(key==root->data){
// 			//0 children
// 			if(root->left==NULL && root->right==NULL){
// 				delete root;
// 				return NULL;
// 			}
//         }
//     }
// return root;
// }

node* del(node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){
        root->left = del(root->left, key);
        
    }
    else if(key > root->data){
        root->right = del(root->right, key);
        
    }
    else{
        // key would be found
        // no children
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
    }
        // 1 child
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;

        }
        else if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        } 
        // 2 children 
        else{
             
                node* temp = root->right;
                temp->left = root->left;
                delete root;
                return temp;
                //  this is wrong .. not accountd for all the cases .only one case taken
        }
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
    root = del(root,2);
    printPre(root);
    return 0;

}