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

// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

void solve()
{
    ll n,t;cin>>n;
    map<ll,ll>mp;
    vector<ll >v ;for(int i=0;i<n;i++){cin>>t;v.push_back(t);mp[t]=1;}
    ll ans=-1;    
    vector<ll> vt;
    for(int  i=1;i<=1024;i++)
    {
       ll cnt=0; 
        for(auto j:v)
        {
            if(mp[i^j]==1){mp[i^j]=2;vt.push_back((i^j));cnt++;}
            else break;
        }
        if(cnt==n){ans=i;break;}
        for(auto j:vt){mp[j]=1;}
        vt.clear();
    }
    cout<<ans<<"\n";

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