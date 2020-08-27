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
int const mxN = 4000+5;
// vector<pair<int,int>> adj[mxN];
vector<tuple<int,int,int,int>> egs;
int link[mxN];
int siz[mxN];

int find(int x){
	if(x != link[x]){
		link[x] = find(link[x]);
	}

	return link[x];
}

void merge(int a,int b){
	a = find(a);
	b = find(b);
	
	if(siz[a]<siz[b]){
		swap(a,b);
	}

	link[b] = a;
	siz[a] += siz[b];
}

void solve(){
	int n,e;
	cin>>n>>e;

	for(int i = 0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		egs.push_back({w,u+v,u,v});
	}
	for(int i = 0;i<=n+1;i++){
		link[i] = i;
		siz[i] = 1;
	}
	sort(egs.begin(),egs.end());
	int ans=0;
	for(auto tp:egs){
		int u,v,sm,w;
		tie(w,sm,u,v) = tp;
		if(find(u) != find(v)){
			merge(u,v);
			ans+=w;
		}

	}

	cout<<ans<< endl;

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