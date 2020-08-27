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
const int mxN = 2e5+5;
vector<int> adj[mxN];
int visited[mxN];
string a = "YES", b = "NO";

int siz;
void dfs(int s,int& ver, int& edg){

	visited[s] = 1;
	ver++;
	edg += adj[s].size();
	for(auto u : adj[s]){
		if(!visited[u]){
			visited[u] = 1;
			dfs(u, ver,edg);
		}
	}
}

void solve(){
	ll n,m;
	cin >> n >> m;
	for(ll i =0; i< m ; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited,0, sizeof(mxN));
	for(int i = 1;i<=n;i++){
		if(!visited[i]){
			int ver=0, edg=0;
			dfs(i,ver,edg);
			if(edg != ((ll)ver * (ver-1))){
				cout << b << endl;
				return;
			}
		}
	}
	cout << a << endl;


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