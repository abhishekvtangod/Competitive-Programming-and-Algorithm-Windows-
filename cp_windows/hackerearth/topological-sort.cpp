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

const int mxN = 20;
vector<int> adj[mxN+2];
int visited[mxN+2];

vector<int> ans;


void dfs(int s){
	if(visited[s]){
		return;
	}
	visited[s] = 1;
	for(auto u:adj[s]){
		dfs(u);
	}
	// cout<<s<<" ";
	ans.push_back(s);
	
}


void solve(){
	
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> pr;
	for(int i =0;i<m;i++){
		int x,y;
		cin>>x>>y;
		pr.push_back({x,y});

	}
	sort(pr.begin(),pr.end(),[](pair<int,int>& p1,pair<int,int>& p2)->bool{
		if(p1.first == p2.first){
			return p1.second >= p2.second;
		}
		p1.first < p2.first;
	});

	for(auto u : pr){
		int x = u.first, y = u.second;
		adj[x].push_back(y);
	}

	memset(visited, 0 , sizeof(visited));
	for(int i=n;i>=1;i--){
		if(!visited[i]){
			dfs(i);
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto u: ans){
		cout<<u<<" ";
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