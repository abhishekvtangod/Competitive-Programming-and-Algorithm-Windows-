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
const int mxN = 10000+5;
vector<int> adj[mxN+1];
vector<int> ans;
int state[mxN+1];
string fl = "Sandro fails.";
 
//state
//0 = unprocessed
//1 = processing
//2 = processed
 
 
void dfs(int s){
	state[s] = 1;
	for(auto u:adj[s]){
		if(state[u] == 0){
			dfs(u);
		}
		else if(state[u] == 1){
			cout<<fl<<endl;
			exit(0);
		}
	}
	state[s] = 2;
	ans.push_back(s);
}
 
 
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	for(int i =1;i<=n;i++){
		sort(adj[i].begin(),adj[i].end(),greater<int>());
	}
	for(int i = n ; i>=1; i--){
		if(state[i] == 0){
			dfs(i);
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto u:ans){
		cout<<u<<" ";
	}
	cout<<endl;
 
}
 
int main()
{   
	IOS;
 
 	#ifndef ONLINE_JUDGE
		freopen("/home/abhi/Documents/input.txt", "r", stdin);
		freopen("/home/abhi/Documents/output.txt", "w", stdout);
	#endif 
 
	// ll t;cin>>t;
	// while(t--){
		solve();
	// }
	
 
    return 0;
} 