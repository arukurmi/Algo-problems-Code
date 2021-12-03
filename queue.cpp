#include<bits/stdc++.h>
using namespace std;
#define ll long long


 // } Driver Code Ends


// Function to print all binary numbers upto n

vector<string> generate(long long N)
{
    vector<string> binary;
	for(long long i=1; i<=N; i++){
	    string binaryofi = "";
	    long long l=0;
	    long long j=i;
	    while(j){
	        // int k=j%2;
            if(j%2)
	            binaryofi += "1";
	        else 
                binaryofi += "0";
            
            j/=2;
	        l++;
	    }
	    binary.push_back(binaryofi);
	}
	return binary;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
} 