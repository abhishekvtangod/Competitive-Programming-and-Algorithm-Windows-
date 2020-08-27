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
    ll t,n;cin>>n;
    ll dp[200005]={0};    
    vector<ll>v1;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
    	cin>>t;
    	v1.push_back(t);
    }
    for(int i=0;i<n;i++){
    	cin>>t;mp[t]=i;
    }
    for(int i=0;i<n;i++)
    {
        if(mp[v1[i]]>=i){
        	dp[mp[v1[i]]-i]++;
        }
        else {
        	dp[n-i+mp[v1[i]]]++;
        }
    }
    ll mx=0;
    for(int i=0;i<200005;i++)
    {
        if(dp[mx]<dp[i])mx=i;
    }
    cout<<dp[mx]<<"\n";
}

int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	// ll t;cin>>t;
	// while(t--)
	// {
		solve();
	// }
	

    return 0;
}