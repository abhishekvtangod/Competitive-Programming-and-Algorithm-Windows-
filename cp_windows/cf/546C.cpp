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
	int n;
	cin >> n;
	int k1,k2;
	cin >> k1;
	queue<int> a;
	int t;
	for(int i=0;i<k1;i++){
		cin >> t;
		a.push(t);
	}
	cin >> k2;
	queue<int> b;
	for(int i=0;i<k2;i++){
		cin >> t;
		b.push(t);
	}
	int cnt = 0;
	for(int i=1;i<10000000;i++){
		if(a.empty()){
			cout << i-1 << " " << "2" << endl;
			return; 
		} else if(b.empty()){
			cout << i-1 << " " << "1" << endl;
			return; 
		}
		int x = a.front();
		int y = b.front();
		// debug(x,y);
		a.pop();
		b.pop();
		if(x<y){
			b.push(x);
			b.push(y);
		} else{
			a.push(y);
			a.push(x);			
		}
	}
	cout << "-1" << endl;
 
 
 
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