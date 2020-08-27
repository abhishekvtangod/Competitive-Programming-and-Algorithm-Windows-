/**
 *    author:  abhishekvtangod
 *    created: 
**/
// #undef _GLIBCXX_DEBUG
// #undef _ABHI
#include<bits/stdc++.h>
using namespace std; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

void debug_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << H << ", ";
  debug_out(T...);
}

#ifdef _GLIBCXX_DEBUG
#define debug(x...) cerr << "[" << #x << "]:[", debug_out(x)
#else
#define debug(...) 42
#endif

// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

void solve(){
	int n, m;
	cin >> n >> m;
	ll cost[n][m], disc[n][m];
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> cost[i][j];
		}
	}
	ll dp[n][m];
	memset(dp, 0, sizeof(dp));
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> disc[i][j];
		}
	}
	ll currMin = 1e17;
	for(int i =0;i<m;i++){
		dp[0][i] = cost[0][i];
		currMin = min(currMin, cost[0][i]);
	}
	for(int i =1;i<n;i++){
		ll tempMin = 1e17;
		for(int j=0;j<m;j++){
			dp[i][j] = min({currMin+cost[i][j],dp[i-1][j]+max(0LL, cost[i][j]-disc[i-1][j])});
			tempMin = min(tempMin, dp[i][j]);
		}
		currMin = tempMin;
	}
	// for(auto &row: dp){
	// 	for(auto col:row){
	// 		cout << col << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << currMin << endl;
	
}

int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif 

	ll t;cin>>t;
	while(t--){
		solve();
	}

    return 0;
}