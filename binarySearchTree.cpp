#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* right;
    node* left;
};

node* createnode(int x){
    node* newnode = new node();
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* insert(node* root, int key){
    if(root==NULL)
        root = createnode(key);
    else{
        if(root->data > key)
            root->left = insert(root->left , key);
        if(root->data < key) 
            root->right = insert(root->right , key);
    }
    return root;
}

node* findmin(node* root){
    while(root->left){
        root = root->left;
    }
    return root;
}

node *deleteNode(node *root,  int key){
    if(root == NULL)
        return root;
    else if(root->data > key)
        root->left = deleteNode(root->left , key);
    else if(root->data < key)
        root->right = deleteNode(root->right , key);
    else{
        if(!root->left && !root->right){
            delete(root);
            root = NULL;
            return root;
        }
        else if(!root->left){
            node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(!root->right){
            node* temp = root->left;
            delete(root);
            return temp;
        }
        else{
            node* temp = findmin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right , temp->data);
            return root;
        }
    }
    return root;
}

void inorder(node* root , vector<int> &v){
    if(root){
        inorder(root->left , v);
        v.push_back(root->data);
        inorder(root->right , v);
    }
}

int getCountOfNode(node *root, int l, int h)
{
        vector<int> v;
    inorder(root , v);
    int count = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i] >= l && v[i] <= h)
            count++;
    }
    return count;
}

void printinorder(node* root){
    if(!root)
        return;
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
    // cout<<endl;
}

void printnode(node* root){
    cout<<"root  ->  "<<root->data<<endl;
}

int main(){
    node* root;
    root=NULL;
    root = insert(root, 54);
    insert(root, 13);
    insert(root, 43);
    insert(root, 33);
    insert(root, 85);
    insert(root, 98);
    insert(root, 5);
    
    printnode(root);
    printinorder(root);
    // cout<<endl;    
    // root = deleteNode(root , root->data);
    // printnode(root);
    // printinorder(root);
    // cout<<endl;
    // deleteNode(root , 13);
    // printnode(root);
    // printinorder(root);
    // cout<<endl;
    // deleteNode(root , 12);
    // printnode(root);
    // printinorder(root);
    cout<<endl;

    cout<<getCountOfNode(root , 50 , 86);

    return 0;
}