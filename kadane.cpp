#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    //////////////////////////////////////////////////////////////
    int a[n];
    for(int i = 0; i<n;i++){
        cin>>a[i];
    }

    // to check weather atleast one element is positive or not;;FOR EXTREME CASES!!!!!!!!!!!!;;;
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
    // to find maximum continous sum of subarray of a[]...........

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
    //////////////////////////////////////////////////////////////
    return 0;
}
