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
struct compare{
	bool operator()(pair<ll,ll>& p1,pair<ll,ll>& p2)
	{
		return p1.first>p2.first;
	}
};

int arr[1000][1000];
int ans[1000006];

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
	
	priority_queue<pair<ll,ll>,compare> pq;
	
	//for(ll i=0;i<r;i++)
		//pq.push({arr[i][0],i});
	
	//while(!pq.empty())
	//{
		
	//}
	
	
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
