#include<iostream>
using namespace std;

int main(){
    int n, i = 0, j = 0;
    cin>>n;
    int a[n]; 
    for(i=0 ; i<n;i++){
    cin>>a[i];
    }
    for (j=0; j<n; j++){
    cout<<a[j]<< " ";
    }
    return 0;
}