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
    ll n,m,c1,c2;cin>>n>>m>>c1>>c2;
    ll a[n][m]={0};
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='.')a[i][j]=1;
            else a[i][j]=0;
        }
    }
    ll d=min(2*c1,c2),d1=c1,ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)continue;
            if(j<m-1 && a[i][j]==a[i][j+1]){ans+=d;j++;}
            else if(j<m-1 && a[i][j]!=a[i][j+1])ans+=d1;
            else if(j==m-1)ans+=d1;
        }
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