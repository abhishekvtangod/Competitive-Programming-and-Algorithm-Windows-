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

const int mxN = 1e6+6;
vector<int> adj[mxN+1];
int visited[mxN+1];
int dp[mxN+1];


void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++){
		cin >> v[i];
	}
	for(int i=0;i<n-1;i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dp[1] = v[1];
	queue<int> q;
	q.push(1);
	int ans = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		visited[x] = 1;
		int cnt = 0;
		for(auto u:adj[x]){
			if(!visited[u]){
				if(v[x]==0){
					dp[u] = v[u];
				}
				if(dp[x]>m || v[x]!=0){
					dp[u] = dp[x] + v[u];
				}
				q.push(u);
				cnt++;
			}
		}
		if(!cnt){
			if(dp[x]<=m){
				ans++;
			}

		}

	}
	cout << ans << endl;
}

int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif 
	memset(visited, 0, sizeof(visited));
	memset(dp, 0, sizeof(dp));
	// ll t;cin>>t;
	// while(t--){
		solve();
	// }

    return 0;
}