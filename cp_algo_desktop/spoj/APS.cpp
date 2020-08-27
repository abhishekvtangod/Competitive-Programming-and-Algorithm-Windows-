/**
 *    author:  abhishekvtangod
 *    created:        
**/

#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define debug(x) cerr<<#x<<": "<<x<<" "<< endl;

typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;

// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

ll f(int n){
	
	for(int i = 2;i*i<=n;i++){
		while(n%i == 0 ){
			return i;
			n/=i;
		}
	}
	if(n>1){
		return n;
	}

}

const int mxN = 1e7+5;
int dp[mxN+1];
ll res[mxN+1];

void sieve(){
	memset(dp,0,sizeof(dp));
	memset(res,0,sizeof(res));

	for(int i =2;i<=mxN;i++){
		if(dp[i]){
			res[i] = res[i-1] + dp[i];
			continue;
		}
		dp[i] = i;
		for(int j = 2*i;j<=mxN;j+=i){
			if(dp[j]){
				continue;
			}
			dp[j] = i;
		}
		res[i] = res[i-1] + dp[i];

	}

}

void solve(){
	int n;
	cin>>n;
	// vector<ll> v(n+1);
	// vector<ll> vv(n+1);
	// v[0] = v[1] = 0;
	// vv[0] = vv[1] = 0;
	// for(int i =2;i<=n;i++){
	// 	// vv[i] = v[i-1] + f(i); 
	// 	v[i] = v[i-1] + dp[i];
	// }
	// cout<<v[n]<<" "<<vv[n]<< endl;
	// cout<<v[n]<<" ";
	cout<<res[n]<<endl;
}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	ll t;cin>>t;
	sieve();
	while(t--){
		solve();
	}
	

    return 0;
}