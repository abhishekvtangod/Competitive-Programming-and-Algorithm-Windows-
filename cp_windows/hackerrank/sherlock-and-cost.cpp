/**
 *    author:  abhishekvtangod
 *    created: 
**/
// #undef _GLIBCXX_DEBUG
// #undef _ABHI
#include<bits/stdc++.h>
using namespace std; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

void debug_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << H << ", ";
  debug_out(T...);
}

#ifdef _GLIBCXX_DEBUG
#define debug(x...) cerr << "[" << #x << "]:[", debug_out(x)
#else
#define debug(...) 42
#endif

// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

void solve(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(int i =0;i<n;i++){
		cin >> v[i];
	}
	ll dpl[n],dph[n];
	memset(dpl, 0, sizeof(dpl));
	memset(dph, 0, sizeof(dph));
	//dpl //if the elemelt is low
	//dph //if the elemelt is high
	for(int i =1;i<n;i++){
		dpl[i] = max({dpl[i-1],dph[i-1]+abs(v[i-1]-1)});
		dph[i] = max({dpl[i-1]+abs(v[i]-1),dph[i-1]+abs(v[i-1]-v[i])});
	}
	cout << max({dpl[n-1],dph[n-1]}) << endl; 


}

int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif 

	ll t;cin>>t;
	while(t--){
		solve();
	}

    return 0;
}