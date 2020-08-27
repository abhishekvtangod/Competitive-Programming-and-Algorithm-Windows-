/**
 *    author:  abhishekvtangod
 *    created: 08.05.2020  
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


#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

ll link[20],size[20];

ll find(ll x)
{
	while(link[x]!=x)x=link[x];
	return x;
}
bool same(ll x, ll y)
{
	return (find(x) == find(y));
}

void unite(ll x,ll y)
{
	ll a = find(x);
	ll b = find(y);
	if(size[a] < size[b])swap(a,b);
	
	size[a] +=size[b];
	link[b] = a;
	
}

void solve()
{
	ll n,m;cin>>n>>m;
	vector<ll> v;
	for(ll i=1;i<=n;i++)link[i]=i;
	for(ll i=1;i<=n;i++)size[i]=1;
	
	
	for(ll i =0;i<n;i++)
	{
		ll x;cin>>x;
		v._push_back(x);
	}
	for(ll i=0i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		unite(x,y);
	}
	ll dp[n+2];
	memset(dp,0,sizeof(dp));
	
	for(ll i=0;i<n;i++)
	{
		
	}
	
	
}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	ll t;cin>>t;
	while(t--)
	{
		solve();
	}
	

    return 0;
}

