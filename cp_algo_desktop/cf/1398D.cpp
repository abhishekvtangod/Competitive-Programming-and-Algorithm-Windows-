/**
 *    author:  abhishekvtangod
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

const int mxN = 200;
ll dp[mxN+1][mxN+1][mxN+1];
vector<int> rr,gg,bb;
int r, g, b;

ll opt(int i, int j , int k){
	if(dp[i][j][k] != -1){
		return dp[i][j][k];
	} 
	
	int best = 0;
	
	if(i < r && j<g){
		dp[i][j][k] = max({dp[i][j][k], rr[i]*gg[j]+opt(i+1,j+1,k)});
	}
	if(i < r && k<b){
		dp[i][j][k] = max({dp[i][j][k], rr[i]*bb[k]+opt(i+1,j,k+1)});
	}
	if(j < g && k<b){
		dp[i][j][k] = max({dp[i][j][k], gg[j]*bb[k]+opt(i,j+1,k+1)});
	}
	debug(i,j,k,best);
	if(i<r){
		dp[i][j][k] = max({dp[i][j][k], opt(i+1,j,k)});
	}
	if(j<g){
		dp[i][j][k] = max({dp[i][j][k], opt(i,j+1,k)});
	}
	if(k<b){
		dp[i][j][k] = max({dp[i][j][k], opt(i,j,k+1)});
	}
	// cout << i << " " << j << " "<< k << endl;
	return dp[i][j][k] = best;
}

void solve(){
	cin >> r >> g  >> b;
	rr.resize(r);
	gg.resize(g);
	bb.resize(b);
	for(int i =0;i<r;i++){
		cin >> rr[i];
	}
	for(int i =0;i<g;i++){
		cin >> gg[i];
	}
	for(int i =0;i<b;i++){
		cin >> bb[i];
	}
	// sort(rr.begin(),rr.end(), greater<int> ());
	// sort(gg.begin(),gg.end(), greater<int> ());
	// sort(bb.begin(),bb.end(), greater<int> ());
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	cout << opt(0,0,0) << endl;

}

int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif 

	// ll t;cin>>t;
	// while(t--){
		solve();
	// }

    return 0;
}

