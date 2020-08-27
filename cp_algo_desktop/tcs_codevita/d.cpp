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

const int mxN = 7000+5;
vector<int> adj[mxN];
int visited[mxN];
int x,y;
void dfs(int s){
	if(visited[s]){
		return;
	}
	visited[s] = 1;
	for(auto u:adj[s]){
		if((x==s && y==u) || (x == u && y==s)){
			continue;
		}

		dfs(u);
	}
}

void solve(){
	int m, n;
	cin >> m >> n;
	vector<pair<int,int>> v;
	for(int i=0;i<m;i++){
		int u,vv;
		cin >> u >> vv;
		v.push_back({u,vv});
		adj[u].push_back(vv);
		adj[vv].push_back(u);
	}
	set<int> s;
	for(int i =0;i<m;i++){
		// memset(visited,0, sizeof(visited));
		for(int &jj:visited){
			jj=0;
		}
		x = v[i].first;
		y = v[i].second;
		dfs(0);
		// cout << x << " " << y <<endl;
		if(!visited[x] || !visited[y]){
			debug(x,y);
			s.insert(x);
			s.insert(y);
		}
	}
	for(auto u:s){
		cout << u << "\n";
	}
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