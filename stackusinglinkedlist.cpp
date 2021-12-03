#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

///////////////GLOBAL   DECLARATION   OF    TOP///////////////////
node* top = NULL;

///////////////PUSH  FUNCTION////////////////////
void push(int i){
    node* temporarynode = new node;
    temporarynode->data = i;
    temporarynode->next = top;
    top = temporarynode;
}

void pop(){
    if( top == NULL){
        cout<<"nothing to pop"<<endl;
    }
    else{
        node* temporarynode = top;
        top = top->next;
        delete temporarynode;
    }
}

void Top(){
    if( top == NULL){
        cout<<"Empty stack"<<endl;
    }
    else
        cout<<"TOP = "<<top->data;
}

void isEmpty(){
    if( top == NULL){
        cout<<"Empty stack"<<endl;
    }
    else 
    cout<<"Stack is not empty"<<endl;
}

void printstack(){
    node* temporarynode = top;
    cout<<"STACK ::   ";
    while(temporarynode != NULL){
        cout<<temporarynode->data<< "  ";
        temporarynode = temporarynode->next;
    }
    cout<<endl;
}

int main(){

    push(4);printstack();
    push(9);printstack();
    push(30);printstack();
    push(98);printstack();
    push(23);printstack();
    pop();printstack();
    push(76);printstack();
    isEmpty();
    push(9);printstack();
    Top();

    return 0;
}