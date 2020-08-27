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

typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;


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
	ll n;cin>>n;
	ll arr[n+1][n+1];
	ll dp[n+2][n+2];
	
	for(ll i=0;i<n;i++)
		for(ll j =0;j<n;j++)
			cin>>arr[i][j];
	memset(dp,0,sizeof(dp));
	for(ll i =1;i<=n;i++)
	{
		for(ll j = 1;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i-1][j-1];
		}
	}
	for(ll i=0;i<=n;i++)
	{
		for(ll j =0;j<=n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	
	for(ll i=0;i<=n;i++)
	{
		for(ll j =0;j<=n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}

	//2D kadane
	ll sum=0;
	for(ll i =1;i<=n;i++){
		for(ll j=0;j<=n;j++){
			sum = max();
		}
	}


}
/*
5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
*/
int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

		solve();

	

    return 0;
}
