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

const ll mxN = 1e6+8;
ll f[mxN+2];

void fact(){
	f[0] = 1;
	for(ll i = 1; i<=mxN;i++){
		f[i] = (f[i-1] * i)%mod; 
	}
	// for(int i = 0;i<20;i++){
	// 	debug(f[i],i);
	// }
}

ll inv(ll n){
	n%=mod;
	ll k = mod-2;
	ll ans = 1;
	while(k>0){
		if(k&1){
			ans = (ans*n+mod)%mod;
		}
		n = (n * n + mod)%mod;
		k/=2;
	}
	return ans;
}

ll C(ll n, ll k){
	// (n!/((n-k)!*k!))
	ll ans =  (f[n] * ((inv(f[n-k]) * inv(f[k]))%mod))%mod;
	return ans;
}


void solve(){
	string s;
	cin >> s;
	ll a=0, b=0, c=0, d=0;
	for(int i =0; i<s.size();i++){
		if(s[i] == 'a'){
			a++;
		} else if(s[i] == 'b'){
			b++;
		} else if(s[i] == 'c'){
			c++;
		} else if(s[i] == 'd'){
			d++;
		}
	}
	ll ans = (C(a+b,b) * C(c+d,d) - 1 + mod) % mod; 
	cout << ans << endl;
}

int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif 
	fact();
	ll t;cin>>t;
	while(t--){
		solve();
	}

    return 0;
}