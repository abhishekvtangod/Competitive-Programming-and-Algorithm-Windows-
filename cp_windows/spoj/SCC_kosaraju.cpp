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

const int mxN = 1e6+6;

vector<int> stk;
vector<int> adj[mxN],r_adj[mxN];

int visited[mxN];

void solve()
{
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		r_adj[v].push_back(u);

	}
	memset(visited,0,sizeof(mxN));
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs1(i);
		}
	}

	// memset(visited,0,sizeof(mxN));
	// for(int i=1;i<=n;i++){
	// 	if(!visited[i]){
	// 		dfs1(i);
	// 	}
	// }


}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	// ll t;cin>>t;
	// while(t--)
	// {
		solve();
	// }
	

    return 0;
}