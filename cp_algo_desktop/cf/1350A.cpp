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





ll check(ll n )
{
    ll ans=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
			ans=min(n/i,i);
			break;
		}
    }
    return ans;
}


void solve()
{
    ll n,k;cin>>n>>k;
    if(n%2==1){
		n+=check(n);k--;
	}
    n+=2*k;
    cout<<n<<endl;
}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
	//seive();
	ll t;cin>>t;
	while(t--)
	{
		solve();
	}
	

    return 0;
}
