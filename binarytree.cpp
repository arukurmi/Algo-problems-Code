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

node* insertnode(node* root, int x){
    if((root)==NULL){
        (root)=createnode(x);
        return root;
    }

    queue<node*> q;
    q.push((root));
    while(!(q.empty())){
        node* temp = q.front();
        q.pop();

        if(temp->left != NULL)
            q.push(temp->left);
        else{
            temp -> left = createnode(x);
            return root;
        }
        if(temp->right != NULL)
            q.push(temp->right);
        else{
            temp -> right = createnode(x);
            return root;
        }
    }
    return root;
}   

void deleterightnode(node* root , node* delnode){
    queue<node*> q;
    q.push(root);
    node* temp;

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if( temp -> right != NULL){
            if( temp ->right == delnode){
                temp->right = NULL;
                delete(temp -> right);
                return;
            }
            else
                q.push(temp->right);
        }
        if( temp -> left != NULL){
            if( temp ->left == delnode){
                temp->left = NULL;
                delete(temp -> left);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

node* deletenode(node* root, int key){
    if( root == NULL ){
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL){
        if(root->data == key)
            return NULL;
        else 
            return root;
    }
    else{
        queue<node*> q;
        node* keynode = NULL;
        node* temp;
        q.push(root);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp->data == key){
                keynode = temp;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        if(keynode!=NULL){
            int k = temp -> data;
            deleterightnode(root , temp);
            keynode->data = k;
            return root;
        }
        else 
            return root;
    }
}

int countnodes(node* root){
    int count = 0;
    queue<node*> q;
    if(root==NULL){
        return 0;
    }
    else{
        q.push(root);
        count++;
        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                count++;
            }
            if(temp->right){
                q.push(temp->right);
                count++;
            }
        }
        return count;
    }
}


pair<int , int> heightdiameter(node* root)
{
    if( root == NULL){
        pair<int , int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    else{
        pair<int, int> left={0,0};
        pair<int, int> right={0,0};
        int lh=0, rh=0 , ld=0 , rd=0;
        if(root->right){
            right = heightdiameter(root->right);
            rh = right.first;
            rd = right.second;
        }
        if(root->left){
            left = heightdiameter(root->left);
            lh = left.first;
            ld = left.second;
        }
        int height = 1 + max(lh,rh);
        int diameter = 1 + max((lh+rh), max(ld, rd));
        // cout<<"root  -  "<<root->data<< "  height   -  " << height<<"  DIAMETER -  "<<diameter<<endl;
        pair<int,int> pp;
        pp.first = height;
        pp.second = diameter;
        return pp;
    }
}

/* Computes the diameter of binary tree with given root.  */
int diameter(node* root) {
    // Your code here
    pair<int,int> p;
    p=heightdiameter(root);
    int d = p.second;
    return d;
}

void printinorder(node* root){
    if(!root)
        return;
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

void printpreorder(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
void printpostorder(node* root){
    if(root == NULL)
        return;
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
}


int main(){
    //          13
    //        /    \
    //     23        2
    //     / \      /
    //    3   83  20

    node* root = createnode(13);
    root->left = createnode(23);
    root->left->right = createnode(83);
    root->left->left = createnode(3);
    root->right = createnode(2);
    root->right->left = createnode(20);
    // cout<<getCountOfNode(root, 10 , 90);
    root = binaryTreeToBST(root);
    cout<<" binary to bst converted"<<endl;
    printinorder(root);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    // int i=1;
    while(1){
        int i;
        cout<<" print root? 1\n insert? 2\n delete? 3\n count nodes? 4\n print inorder? 5\n print preorder? 6\n print postorder? 7\n diameter? 8\n\n"<<endl;
        cin>>i;
        if(i==1){
            cout<<"ROOT ->>   "<<root->data;
            // printinorder(root);
            cout<<"\n";
        }
        else if(i==2){
        cout<<"enter number to insert"<<endl;
        int num;
        cin>>num;
        root = insertnode(root, num);
        }
        else if(i==3){
            cout<<"enter number to delete"<<endl;
            int num;
            cin>>num;
            root = deletenode(root , num);
        }
        else if(i==4){
            cout<<"Nodes in the tree = "<< countnodes(root)<<endl;
            // int num;
            // cin>>num;
            // root = deletenode(root , num);
        }
        else if(i==5){
            cout<<"TREE IN INORDER ->>   ";
            printinorder(root);
            cout<<"\n";
        }
        else if(i==6){
            cout<<"TREE IN PREORDER ->>   ";
            printpreorder(root);
            cout<<"\n";
        }
        else if(i==7){
            cout<<"TREE IN POSTORDER ->>   ";
            printpostorder(root);
            cout<<"\n";
        }
        else if(i==8){
            cout<<"DIAMETER ->>   "<<diameter(root);
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
