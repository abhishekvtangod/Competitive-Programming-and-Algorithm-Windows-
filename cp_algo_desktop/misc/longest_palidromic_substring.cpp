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
	string s;
	cin >> s;
	int n = s.size();
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	// length 1
	int mxLn = 0,start = 0;
	for(int i =0;i<n;i++){
		dp[i][i] = 1;
		start = i;
		mxLn = 1;
	}
	// length 2
	for(int i =0;i<n-1;i++){
		if(s[i] == s[i+1]){
			dp[i][i+1] = 1;
			start = i;
			mxLn = 2;
		}
	}
	//greator than 2
	//k- length of substring 
	for(int k = 3;k<=n;k++){
		//fixing starting index
		for(int i = 0;i<n-k+1;i++){
			int j = i+k-1;

			if(dp[i+1][j-1] == 1 && s[i]== s[j]){
				dp[i][j] = 1;
				if(mxLn < k){
					start = i;
					mxLn = k;
				}
			}
		}
	}
	cout << mxLn << endl;
	for(int i = start;i<start+mxLn;i++){
		cout << s[i];
	}
	cout << endl;

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