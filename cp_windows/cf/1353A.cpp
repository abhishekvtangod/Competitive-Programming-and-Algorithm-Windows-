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
	ll n,m;
	cin>>n>>m;
	
	
	
	
	if(n==1)
	{
		cout<<"0"<<endl;
		return;
	}
	if(n==2)
	{
		cout<<m<<endl;
		return;
	}
	
	if(n==3 || n==4)
	{
		cout<<m*2<<endl;
		return;		
	}


	
	
	ll ele = m/2;

	//ll ans = ele*2;
	if(m%2==0)
	{
		//ans+=ele*2;
		cout<<m*2;
				

	}
	else
	{
		//ans+=(ele+1)*2;
		cout<<max(m*2,ele*2+((ele+1)*2));
	}
	
	
	cout<<endl;
	
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
