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
	ll n,r,avg;cin>>n>>r>>avg;
	vector<pair<ll,ll>> v;
	ll sum=0;
	for(int i =0;i<n;i++){
		ll a,b;cin>>a>>b;
		v.push_back({b,a});
		sum+=a;
	}
	
	if(sum>=avg*n){
		cout<<"0"<< endl;return;
	}
	sort(v.begin(),v.end());

	// for(int i =0;i<n;i++){
	// 	cout<<v[i].second<<" "<<v[i].first<< endl;
	// }
	int i = 0;
	ll ans = 0;
	while(sum < avg*n){
		ll temp = min(r-v[i].second,avg*n-sum);
		ans += temp*v[i].first;
		sum += temp;
		i++;
	}
	cout<<ans<< endl;


}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif



		solve();
		

    return 0;
}