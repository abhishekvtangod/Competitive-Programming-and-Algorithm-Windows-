/**
 *    author:  abhishekvtangod
 *    created: 12.05.2020       
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




void solve()
{
	ll n;cin>>n;
//	vector<ll> v;
	set<ll> temp;
	for(ll i=0;i<n;i++)
	{
		ll x;cin>>x;
		temp.insert(x);
	}
	vector<ll>v(temp.begin(),temp.end());
	while(v.size()>2)
	{
		set<ll> s;

		for(ll i=0;i<(ll)v.size();i+=2)
		{
			s.insert(lcm(v[i],v[i+1]));
		}
		if(v.size()%2==1)s.insert(v[v.size()-1]);
		v.clear();
		for(auto u:s)v.push_back(u);		
	}	
	
	ll ans=0;
	
	if(v.size()==2)
		ans = gcd(v[0],v[1]);
	else
		ans = v[0];
	
	cout<<ans<<endl;
	
	
}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);


		solve();
	

    return 0;
}

