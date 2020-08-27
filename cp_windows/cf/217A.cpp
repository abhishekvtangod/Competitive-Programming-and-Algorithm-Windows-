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



// --------dsu------
// const int mxN = 100+6;
// int link[mxN],siz[mxN];
// vector<pair<int,int>> v;

// int find(int x){
// 	if(link[x]!=x){
// 		link[x]=find(link[x]);

// 	}
// 	return link[x];
// }

// void unite(int i,int j){
// 	int a = find(i);
// 	int b = find(j);
// 	if(a==b){
// 		return;
// 	}

// 	if(siz[a]<siz[b]){
// 		swap(a,b);
// 	}
// 	link[b]=a;
// 	siz[a]+=siz[b];


// }


// void solve_dsu(){
// 	int n;
// 	cin>>n;
// 	for(int i=0;i<n;i++){
// 		int x,y;cin>>x>>y;
// 		v.push_back({x,y});
// 		link[i]=i;
// 		siz[i]=1;
// 	}
// 	for(int i =0;i<n;i++){
// 		for(int j = i+1;j<n;j++){
// 			if(v[i].first == v[j].first || v[i].second == v[j].second){
// 				unite(i,j);
// 			}
// 		}
// 	}
// 	int cnt=0;
// 	for(int i =0;i<n;i++){
// 		if(link[i]==i){
// 			cnt++;
// 		}
// 	}
// 	cout<<cnt-1<< endl;

// }

// --------dfs------
const int mxN = 1e5+6;
vector<int> x,y;
int vis[mxN];
int n;
void dfs(int s){
	if(vis[s]){
		return;
	}
	vis[s]=1;

	for(int i =0;i<n;i++){
		if(x[i]==x[s] || y[i]==y[s]){
			dfs(i);
		}
	}


}

void solve_dfs(){
	cin>>n;


	for(int i =0;i<n;i++){
		int xx,yy;cin>>xx>>yy;
		x.push_back(xx);
		y.push_back(yy);
		vis[i]=0;
	}
	int cnt=0;
	for(int i =0;i<n;i++){
		if(!vis[i]){
			cnt++;
			dfs(i);
		}
	}
	cout<<cnt-1;
}


int main()
{
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif

		// solve_dsu();
		solve_dfs();

	

    return 0;
}