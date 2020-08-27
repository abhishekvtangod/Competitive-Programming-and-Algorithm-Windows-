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

const int mxN = 45;
vector<int> v;
int n;
// int memo[mxN][2];

// int opt(int k,int flag){
// 	if(k <= 0){
// 		return 0;
// 	}
// 	if(flag==1 && k==1){
// 		return 0;
// 	}
// 	if(memo[k][flag]!=-1){
// 		return memo[k][flag];
// 	}

// 	int incl = opt(k-2,flag) + v[k-1];
// 	if(k==n){
// 		flag = 0;
// 	}
// 	int excl = opt(k-1,flag);
// 	return memo[k][flag] = max({incl,excl});
// }

int dp[mxN];

int iter_opt(int m,int n){
	memset(dp,0,sizeof(dp));
	for(int i =m;i<=n;i++){
		if(i <=m){
			dp[i] = 0;
			continue;
		}
		if(i == m+1){
			dp[i] = v[i-1];
			continue;
		}
		int incl = dp[i-2] + v[i-1];
		int excl = dp[i-1];

		dp[i] = max({incl,excl});
	}

	return dp[n];


}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	// memset(memo,-1,sizeof(memo));
	
	// cout<<opt(n,1)<< endl;
	cout<<max({iter_opt(1,n),iter_opt(0,n-1)})<< endl;


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