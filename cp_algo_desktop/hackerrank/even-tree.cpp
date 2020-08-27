/**
 *    author:  abhishekvtangod
 *    created: 2020-07-09 13:44
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

const int mxN = 100+5;
vector<int> adj[mxN];
int visited[mxN];

int cnt = 0;

int dfs(int s){
	if(visited[s]){
		return 0;
	}
	visited[s] = 1;
	int down = 1;
	for(auto u:adj[s]){
		down += dfs(u);
	}
	if(down%2==0){
		cnt++;
		return 0;
	}
	return down;
}

void solve(){
	int n, e;
	cin >> n >> e;
	memset(visited,0,sizeof(visited));

	for(int i =0;i<e;i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	if(!dfs(1)){
		cout << cnt - 1 << endl;
	}else{
		cout << cnt << endl;
	}

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