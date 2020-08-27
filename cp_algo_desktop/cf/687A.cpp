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

const int mxN = 1e5+5;
vector<int> adj[mxN];
int visited[mxN];
int color[mxN];
vector<int> a,b;
void dfs(int s){
	visited[s] = 1;

	for(auto u: adj[s]){
		if(!visited[u]){
			color[u] = !color[s];
			dfs(u);	
		}
	}
	if(color[s]==1){
		a.push_back(s);
	} else{
		b.push_back(s);
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i =1;i<=n;i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	for(int i =1;i<=n;i++){
		for(auto u:adj[i]){
			if(color[i] == color[u]){
				cout << "-1" << endl;return;
			}
		}
	}
	cout << a.size() << endl;
	for(auto u:a){
		cout << u << " ";
	}
	cout << endl;

	cout << b.size() << endl;
	for(auto u:b){
		cout << u << " ";
	}
	cout << endl;



}

int main()
{   
	IOS;
	memset(visited,0, sizeof(visited));
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