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




void solve()
{
    string s;cin>>s;
    set<char> st(s.begin(),s.end());
    if(st.size()<3){cout<<"0\n";return;}
    ll a=0,b=0,c=0,ans=s.length();
    for(int i =0;i<s.length();i++)
    {

        if(s[i]=='1')a=i+1;
        else if(s[i]=='2')b=i+1;
        else c=i+1;
        if(a!=0 && b!=0 && c!=0)
        {
            ans=min(ans,max({abs(a-b),abs(b-c),abs(a-c)}));
        }
        // cout<<a<<" "<<b<<" "<<c<<" "<<ans<<"\n";
    }    
    cout<<ans+1<<"\n";
}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	ll t;cin>>t;
	while(t--)
	{
		solve();
	}
	

    return 0;
}
