/**
 *    author:  abhishekvtangod
 *    created: 12.05.2020       
**/

#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)

typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> 
using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };




void solve()
{
	ll t,n;cin>>n;
	vector<ll> v;
	v.push_back(0);
	for(ll i=0;i<n;i++){
		cin>>t;
		v.push_back(t);
	}
	vector<ll> dp(n+1,1);
	
	ll mx=0;
	
	
	for(ll i=1;i<=n;i++)
	{
		for(ll j = 2*i;j<=n;j+=i){
			
			if(v[i]<v[j])
			{
				dp[j] = max(dp[j],dp[i]+1);
				
			}
		}
		
			mx = max(mx,dp[i]);
	}
	
	
	cout<<mx<<"\n";
}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	ll t;cin>>t;
	while(t--)
	{
		solve();
	}
	

    return 0;
}
