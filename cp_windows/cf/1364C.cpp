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
    ll n,t;cin>>n;
    ll visit[100000]={0};
    ll cur=0;
    vector<ll> v;for(int i=0;i<n;i++){cin>>t;v.push_back(t);visit[t]=1;}
    vector<ll> ans;
    for(int i=0;i<n;i++)
    {
        if(i+1<v[i]){cout<<"-1\n";return;}
        if(visit[cur]==0){
            visit[cur]=1;
            ans.push_back(cur++);
            while(i+1<n && v[i+1]==v[i]){while(visit[cur]==1)cur++;ans.push_back(cur);visit[cur++]=1;i++;}
            visit[v[i]]=0;
            cur=v[i];
        }
        else
        {
            while(visit[cur]==1)cur++;
            visit[cur]=1;
            ans.push_back(cur++);
            while(i+1<n && v[i+1]==v[i]){while(visit[cur]==1)cur++;ans.push_back(cur);visit[cur++]=1;i++;}
            visit[v[i]]=0;
            cur=v[i];
        }
    }
    for(auto i:ans)cout<<i<<" ";
    cout<<"\n";
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