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

const int mxN = 1e3+6;
int link[mxN],siz[mxN];

int find(int x){
	if(x!=link[x]){
		link[x]=find(link[x]);
	}
	return link[x];

}

void unite(int u,int v){
	int a = find(u);
	int b = find(v);

	if(a==b){
		return;
	}

	if(siz[a]<siz[b]){
		swap(a,b);
	}

	link[b]=a;
	siz[a]+=siz[b];
}


void solve()
{
	int n,q;cin>>n>>q;
	for(int  i =1;i<=n;i++){
		siz[i]=1;
		link[i]=i;
	}

	for(int i=0;i<q;i++){
		int u,v;cin>>u>>v;
		for(int j=0;j<=ceil((v-u)/2);j++){
			// cout<<j+u<<" "<<v-j<<" "<<j<<endl;
			unite(j+u,v-j);
		}
	}
	set<int> s;
	for(int i =1;i<=n;i++){
		s.insert(find(i));
	}
	ll ans=1;

	for(int i=0;i<s.size();i++){
		ans*=10;
		ans%=mod;
	}

	cout<<ans<< endl;

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