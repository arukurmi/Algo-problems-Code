#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
int a[MAX];
int top = -1;

void push( int i){
    if ( top == MAX - 1 ){
        cout<<"ERROR: stack overflow"<<endl;
        return; 
    }
    else {
        top++;
        a[top] = i;
    } 
}

void pop(){
    if (top == -1){
        cout<<"Nothing to pop"<<endl;
    }
    else 
        top--;
}

int Top(){
    return a[top];
}

void isEmpty(){
    if( top == -1){
        cout<<"Stack is empty";
    }    
    else
        cout<<"Stack is not empty";
}

void printstack(){
    cout<<"STACK :: ";
    if(top == -1){
        cout<<"EMPTY"<<endl;
    }
    else {
        for(int i=0 ; i<=top; i++){
            cout<<a[i]<<"  ";
        }
    }
    cout<<endl;
}

int main(){
    push(2);
    push(5);
    push(20);
    printstack();
    push(12);
    pop();
    pop();
    printstack();
    pop();
    pop();
    pop();
    isEmpty();

    
    return 0;
}