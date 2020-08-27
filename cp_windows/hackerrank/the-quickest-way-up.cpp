/**
 *    author:  abhishekvtangod
 *    created: 2020-07-09 20:57
**/

#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define debug(x...) cerr << "[" << #x <<" : "<<x<<"] "<< endl;

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

vector<int> adj[102];
int visited[102];
int dist[102];

int bfs(int s){
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while(!q.empty()){
		int a = q.front();
		q.pop();
		for(auto u:adj[a]){
			if(!visited[u]){
				visited[u] = 1;
				dist[u] = dist[a] + 1;
				q.push(u);
			}
		}
	}
	// for(int i =1;i<=100;i+=10){
	// 	for(int j =i;j<i+10;j++)
	// 		cout << dist[j] << " ";
	// 	cout << endl;
	// }
	// cout << endl;
	// cout << endl;
	// cout << endl;
	return dist[100];
}

void solve(){
	int n,m;
	cin >> n;
	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	for(int i =0;i<=100;i++){
		adj[i].clear();
	}
	for(int i =1 ;i<=100;i++){
		for(int j=i+1;j<=i+6 && j<=100;j++){
			adj[i].push_back(j);
		}
		// sort(adj[i].begin(),adj[i].end(),greater<int>());
	}
	for(int i =0;i<n; i++){
		int x, y;
		cin >> x >> y;
		adj[x].clear();
		for(int j = x-1;j>=1 && j>=x-6;j--){
			for(auto& u:adj[j]){
				if(u == x){
					u = y;
				}
			}
		}
	}
	cin >> m;
	for(int i =0;i<m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].clear();
		for(int j = x-1;j>=1 && j>=x-6;j--){
			for(auto& u:adj[j]){
				if(u == x){
					u = y;
				}
			}
		}
	}
	int ans = bfs(1);
	cout << (ans?ans:(-1)) << endl;
	// for(int i =1;i<=100;i++){
	// 	for(auto u:adj[i]){
	// 		cout << u << " ";
	// 	}
	// 	cout << endl;
	// }


}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	ll t;cin>>t;
	while(t--){
		solve();
	}
	

    return 0;
}