/**
 *    author:  abhishekvtangod
 *    created: 2020-07-09 18:03
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

const int mxN = 3000+6;
vector<pair<int, int>> adj[mxN];
int n, m;
int processed[mxN];

ll prim(int s){
	memset(processed, 0, sizeof(processed));
	priority_queue<pair<int,int>> pq;

	pq.push({0,s});
	ll ans = 0;
	while(!pq.empty()){
		int a = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if(processed[a]){
			continue;
		}		
		processed[a] = 1;
		ans += abs(w);
		for(auto u:adj[a]){
			pq.push({-u.second,u.first});
		}
		// cout << a << endl;

	}

	return ans;
}

void solve(){
	cin >> n >> m;
	for(int i =0;i<m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	int start;
	cin >> start;
	cout << prim(start) << endl;
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