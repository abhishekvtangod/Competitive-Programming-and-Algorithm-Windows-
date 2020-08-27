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


void solve()
{
	ll n,m,k;cin>>n>>m>>k;
	ll t = n/k;
	ll rem = t-m;
	ll dv=0;
	if(rem<0){
		rem = abs(rem);
		// cout<<rem<<" ";
		dv = (rem)/(k-1);
		// cout<<dv<<" ";
		rem -= ((rem)/(k-1))*(k-1);
		// cout<<rem<<" ";
		if(rem){
			dv+=1;
		}
	}
	else
	{
		cout<<m<<endl;return;
	}
	cout<<abs(t)-dv<<endl;
}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	ll t;cin>>t;
	while(t--)
	{
		solve();
	}
	

    return 0;
}