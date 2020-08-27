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

void solve()
{
	double p,q,r,a,b,c;cin>>p>>q>>r>>a>>b>>c;
	if(p==a && q==b && r==c){
		cout<<"0"<< endl;
		return;
	}
	//if 1 is the answer
	// double x = a - p, y = b - q, z = c - r;
	// if((x == y && y == z) || (x == y && z==0) || (x==z && y==0) || (y==z && x==0)){
	// 	cout<<"1"<< endl;
	// 	return;
	// }
	// double m = a/p, n = b/q, o = c/r;

	// if((m == n && n == z) || (m == n && o==1) || (m==o && n==1) || (n==o && m==1)){
	// 	cout<<"1"<< endl;
	// 	return;
	// }

	// cout<<p<<"-<\n";

	//if 2 is the answer

	//++
	double x = a - p, y = b - q, z = c - r;
	if(x+y==z || x+z==y || z+y==x || x==y || y==z || x==z){
		cout<<"2"<< endl;
		return;
	}
	// **
	if(a%p ==0 && b%q==0 && c%r==0){
		x = a/p;
		y = b/q;
		z = c/r;
		if(x*y==z || x*z==y || y*z==x || x==y || y==z || z==x){
			cout<<"2"<< endl;
			return;
		}
	}
	// *+
	


	//if 3 is the answer
	cout<<"3"<< endl;

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