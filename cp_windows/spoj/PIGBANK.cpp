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

void solve(){
	string a = "The minimum amount of money in the piggy-bank is ", b = "This is impossible.";
	
	int e,f;
	cin>>e>>f;
	int W = f-e;
	int n;
	cin>>n;
	vector<int> val(n+1);	
	vector<int> wt(n+1);	
	for(int i =1;i<=n;i++){
		cin>>val[i]>>wt[i];
	}
	int dp[W+1];
	memset(dp,0,sizeof(dp));

	for(int w =0;w<=W;w++){
		for(int i = 1;i<=n;i++){
			if(wt[i] <= w){
				dp[w] = max({
					dp[w],
					val[i] + dp[w-wt[i]]
				}); 
			}
		}
	}
	cout<<dp[W]<< endl;

}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	ll t;cin>>t;
	while(t--){
		solve();
	}
	

    return 0;
}