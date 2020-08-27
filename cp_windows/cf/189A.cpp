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

const int mxN = 5000;
int a,b,c,n;
ll memo[mxN];

ll opt(int n){
	if(n == 0){
		return 0;
	}
	if(n<0){
		return -1000000000;
	}
	if(memo[n] != -1){
		return memo[n];
	}

	ll ans = max({opt(n-a),opt(n-b),opt(n-c)})  + 1 ;
	return memo[n] = ans;

}

void solve(){
	cin>>n>>a>>b>>c;
	memset(memo,-1,sizeof(memo));
	cout<<opt(n)<< endl;
}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	// ll t;cin>>t;
	// while(t--)
	// {
		solve();
	// }
	

    return 0;
}