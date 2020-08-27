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
	int n;cin>>n;
	vector<int>v(5);
	for(int i =0 ;i<n;i++){
		int t;cin>>t;
		v[t]++;
	}
	int ans = v[4];
	int three = min(v[3],v[1]);
	v[3] -= three;
	v[1] -= three;
	ans += three + v[3];

	ans += (v[2]/2);
	v[2]-= (v[2]/2)*2;

	if(v[2]==1){
		if(v[1]==1 || v[1]==0 || v[1] ==2){
			v[1]=0;
			ans++;
		}
		else{
			ans++;
			v[1]-=2;

		}
	}
	int one = v[1]/4;
	ans+=one;
	if(v[1]%4){
		ans++;
	}

	cout<<ans << endl;

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