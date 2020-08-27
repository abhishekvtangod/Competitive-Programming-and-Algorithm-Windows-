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

int const mxN = 1e7+5;

vector<int> v(mxN);
int dp[mxN];

int opt(int start,int n){

	if(n - start + v[start]  <=0){
		return 1;
	}
	int ans = 0;
	for(int i = start;i<=v[start];i++){
		ans = min({ans,})
	}

	return ans;

	int incl = 

	int excl = 

	return min({incl,excl});
}

void solve(){
	int n;cin>>n;
	for(int i= 1 ; i<= n;i++){
		cin>>v[i];
	}
	memset(dp,0,sizeof(dp));
	cout<<opt(1,n)<< endl;

}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	// ll t;cin>>t;
	// while(t--){
		solve();
	// }
	

    return 0;
}