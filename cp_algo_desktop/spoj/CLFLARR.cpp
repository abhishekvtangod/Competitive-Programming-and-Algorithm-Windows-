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

const int mxN = 2e5+5;

int link[mxN],color[mxN];

int find(int x){

	if(x!=link[x]){
		link[x]=find(link[x]);
	}
	return link[x];

}

// void unite(int u,int v){
// 	int a = find(u);
// 	int b = find(v);
// 	if(a==b){
// 		return;
// 	}
// 	if(a<b){
// 		swap(a,b);
// 	}
// 	link[b]=a;


// }

void solve()
{
	int n,q;
	cin>>n>>q;

	for(int i = 0;i<=n+1;i++){
		color[i]=0;
		link[i]=i;
	}
	
	
	vector<tuple<int,int,int>> v;
	for(int i =0;i<q;i++){
		int l,r,c;cin>>l>>r>>c;
		v.push_back({l,r,c});
	}

	//dsu on reverse querying

	for(int i =q-1;i>=0;i--){
		int l,r,c;

		tie(l,r,c) = v[i];

		for(int j = find(l);j<=r;j = find(j)){
			color[j]=c;
			link[j]=j+1;
			// cout<<j<<" "<<color[j]<<" "<<i<<endl;
		}

	}

	for(int i =1;i<=n;i++){
		cout<<color[i]<<endl;
	}



}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif



		solve();


    return 0;
}