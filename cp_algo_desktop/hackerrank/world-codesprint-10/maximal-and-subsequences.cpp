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



ll bigmod(ll a, ll p){
	//pow(a,p)%mod
	ll ans = 1;
	ll x = a%mod;
	while(p){
		if(p&1){
			ans = (ans*x)%mod;
		}
		x = (x * x) % mod;
		p/=2;
	}
	return ans;

}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for(int i = 0;i<n;i++){
		cin >> v[i];
	}
	for(int i = 61; i>=0;i--){
		int cnt = 0;
		vector<ll> temp;
		for(int j = 0;j<v.size();j++){
			if((1LL<<i)&(v[j])){
				cnt++;
				temp.push_back(v[j]);
			}
		}
		if(cnt>=k){
			v = temp;
		}
	}
	ll ans = v[0];	
	for(int i = 1;i< v.size();i++){
		ans = ans & v[i];
	}
	cout << ans << endl;

	//possible combinations
	//nCk
	n = v.size();

	//n!
	ll n_fac = 1, nk_fac =1,k_fac = 1;
	for(int i =1;i<=n;i++){
		n_fac = (n_fac*i)%mod;
	}
	for(int i =1;i<=k;i++){
		k_fac = (k_fac*i)%mod;
	}
	for(int i =1;i<=n-k;i++){
		nk_fac = (nk_fac*i)%mod;
	}
	k_fac = bigmod(k_fac,mod-2);
	nk_fac = bigmod(nk_fac,mod-2);
	// euler 
	// a * pow(b,p-2)%p

	ll res = (n_fac * k_fac) % mod;
	res = (res * nk_fac) % mod;

	cout << res << endl;



}

int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif 

	// ll t;cin>>t;
	// while(t--){
		solve();
	// }

    return 0;
}