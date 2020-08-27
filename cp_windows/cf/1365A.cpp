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
	ll arr[51][51]={0};
	ll row[51]={0},col[51]={0};
    ll n,m;cin>>n>>m;
     queue<pair<ll,ll>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0){q.push({i,j});}
            else {row[i]=1;col[j]=1;}
        }
    }
    ll a=0,v=0,c=1;
    while (!q.empty())
    {
        auto t=q.front();q.pop();
        if(arr[t.first][t.second]==1)continue;
        if(row[t.first]==1 || col[t.second]==1)continue;
        // cout<<t.first<<" "<<t.second<<"\n";
        for(int i=0;i<m;i++)
        {
                arr[t.first][i]=1;
        }
        for(int i=0;i<n;i++)
        {
            arr[i][t.second]=1;
        }
        c=c^1;
        // cout<<c<<" ";
    }
        if(!c)cout<<"Ashish\n";
        else cout<<"Vivek\n";

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