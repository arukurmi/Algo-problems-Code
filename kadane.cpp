#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n;i++){
        cin>>a[i];
    }
    int count = 0;
    for (int j=0; j<n; j++){
        if (a[j]<n){
            count++;
        }
    }
    if (count == n){
        cout<<0;
        exit(0);
    }

    int max = INT_MIN;
    int sum =0;
    for ( int i=0; i<n ; i++){
        sum += a[i];
        if (sum < 0){
            sum = 0;
        }
        if(sum > max){
            max = sum;
        }
    }
    cout<<max;
    return 0;
}