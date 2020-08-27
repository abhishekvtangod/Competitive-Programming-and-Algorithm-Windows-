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
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	int dp[n][3];
	for(int i =0; i < n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i =0;i<n;i++){
		for(int j =0;j<3;j++){
			dp[i][j] = 0;
 		}
	}
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];

	for(int i =1;i<n;i++){
		dp[i][0] = max({dp[i-1][1],dp[i-1][2]}) + a[i];
		dp[i][1] = max({dp[i-1][0],dp[i-1][2]}) + b[i];
		dp[i][2] = max({dp[i-1][1],dp[i-1][0]}) + c[i];
	
		// cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << endl;
	}

	cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;


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