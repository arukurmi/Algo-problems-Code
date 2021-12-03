#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define fori(i, a, b) for (ll i = (a); i < (b); i++)
#define ford(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(1);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
const ll mod=1e9+7;
ll INF=1e18;
const ll N=300005;
//power calculator using exponentiation
ll po(ll a,ll b)
{
	ll re=1;  
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}

void solve(){
    int n;
    cin>>n;
    
    if(n >=42 && n<100){
        cout<<"AGC0"<<n+1<<endl;
    }
    else if(n>100){
        cout<<"AGC"<<n<<endl;
    }
    else if(n<10 && n>0){
        cout<<"AGC00"<<n<<endl;
    }
    else{
        cout<<"AGC0"<<n<<endl;
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
	return 0;
}