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

ll f(ll x,ll y,ll z){
	return (x&z)*(y&z);
}
	

void solve()
{
	ll x,y,l,r;cin>>x>>y>>l>>r;
	
	vector<ll> v;
	
	v.push_back(l);
	v.push_back(r);
	
	ll ans=0;
	int i;
	for(i= 42;i>=0;i--)
	{
		if(((1LL<<i) & r ) != ((1LL<<i) & l))
		{
			break;
		}
		
		ans|=((1LL<<i)&r);
		
	}
	
	ll k = i;
	for(;k>=0;k-- )
	{
		if(((1LL<<k) & r))
		{
			//v.push_back(ans|=((1LL<<k)-1));
			v.push_back((((1LL<<k)-1))&r);
		
		}
		ans|=((1LL<<k)&r);
	}
	
	sort(v.begin(),v.end());
	ll mx=f(x,y,v[0]);
	ll z = v[0];
	for(ll i=1;i<(ll)v.size();i++)
	{
		//mx = max(mx,f(x,y,v[i]));
		if(mx < f(x,y,v[i]))
		{
			z = v[i];
			mx = f(x,y,v[i]);
		}
	}
	
	cout<<z<<"\n";
	//cout<<mx<<endl;
	
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
