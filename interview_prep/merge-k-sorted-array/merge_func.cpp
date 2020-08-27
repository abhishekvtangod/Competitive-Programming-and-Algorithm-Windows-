/**
 *    author:  abhishekvtangod
 *    created: 28.04.2020 08:34:03 IST       
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

int arr[1000][1000];
int ans[1000005];

void merge(ll f,ll l,ll c)
{
	ll i=0;j=0;
	while(i<f && i<l)
	{
		if(arr[i]<arr)
	}
}

void divide(ll i,ll j,ll c)
{
	if(i == j)
		return;
	ll mid = i+(j-i)/2;
	divide(i,mid,c);
	divide(mid+1,j,c);
	merge(i,j,c);
}

void solve()
{
	ll r,c;cin>>r>>c;
	for(ll i=0;i<r;i++)
	{
		for(ll j=0;j<c;j++)
		{
			cin>>arr[i][j];
		}
	}
	divide(0,r);

}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	//ll t;cin>>t;
	//while(t--)
	//{
		solve();
	//}
	

    return 0;
}
