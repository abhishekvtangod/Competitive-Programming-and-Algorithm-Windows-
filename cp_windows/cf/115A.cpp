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



int const mxN = 2e3+5;
vector<int> adj[mxN];
int vis[mxN];


int dfs(int x){
	// cout<<x<<endl;
	vis[x]=1;
	int mx = 1;
	for(auto u:adj[x]){
		if(!vis[u]){
			mx = max({mx,dfs(u)+1});
		}
	}
	return mx;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> vv;
	for(int i =1;i<=n;i++){
		int x;cin>>x;
		if(x == -1){
			vv.push_back(i);
			continue;
		}
		adj[x].push_back(i);
		adj[i].push_back(x);
		vis[i]=0;
	}
	int mx=0;
	// for(int i =1;i<=n;i++){
	// 	if(!vis[i]){
	// 		mx = max({mx,dfs(i)});
	// 		cout<<dfs(i)<< endl;
	// 	}
	// }
	for(auto u:vv){
		if(!vis[u]){
			mx = max({mx,dfs(u)});
			// cout<<dfs(u)<<endl;
			// cout<<u<<endl;
		}
	}
	cout<<mx<< endl;

}

int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif



	solve();

	

    return 0;
}