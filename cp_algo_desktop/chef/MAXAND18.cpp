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

void solve(){

        ll n,k,t;cin>>n>>k;
        vector<ll> v;
        for(int i=0;i<n;i++){
        	cin>>t;v.push_back((ll)t);
        }
        vector<pair<ll,ll>> ans;
        for(int i=0;i<=31;i++)
        { 
            ll t=0;
            for(int j=0;j<n;j++)
            	t+=(((1<<i)&v[j]) == (1<<i));

            ans.push_back({i,t*(1<<i)});
        }
        // sort(ans.begin(),ans.end(),[](pair<ll,ll>p1,pair<ll,ll>p2)->bool{
        //         if(p1.first*(1<<p1.second)==p2.first*(1<<p2.second))
        //             return p1.second<p2.second;
        //     return (p1.first*(1<<p1.second)>p2.first*(1<<p2.second));
        // });
        sort(ans.begin(),ans.end(),[](pair<ll,ll>p1,pair<ll,ll>p2)->bool{
        	if(p1.second == p2.second){
        		return p1.first<=p2.first;
        	}
        	return p1.second > p2.second;

        });
        int i,anss=0;
        for( i=0;i<k;i++)
        {
            // if(ans[i].second==0)break;
            anss|=(1<<ans[i].first);
            // cout<<anss<<" ";
        }
        int j=0;
        // cout<<i<<" ";
        while(i<k && j<=31)
        {
            if(((1<<j)& anss) ==0){
            	anss|=(1<<j);i++;
            }
            j++;
        }

        cout<<(int)anss<<"\n";
    }


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	ll t;cin>>t;
	while(t--){
		solve();
	}
	

    return 0;
}