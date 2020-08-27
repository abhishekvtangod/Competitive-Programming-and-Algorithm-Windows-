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

void solve()
{
	int n,sum;
	cin>>n>>sum;
	vector<int> v(n);
	for(int i =0;i<n;i++){
		cin>>v[i];
	}


	int dp[sum+1];
	dp[0] = 0;
	for(int i = 1;i<=sum;i++){
		dp[i] = 100000000+9;
	}
	for(int i =1;i<=sum;i++){
		for(int j = 0;j < n;j++){
			if(v[j] <= i ){
				dp[i] = min(dp[i],dp[i-v[j]]+1);
			}
		}

	}
	for(int i : dp){
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<dp[sum]<< endl;


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