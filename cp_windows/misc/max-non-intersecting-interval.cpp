/**
 *    author:  abhishekvtangod
 *    created: 2020-08-15 00:05
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

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i=0;i< n;i++){
		int u,vv;
		cin >> u >> vv;
		v.push_back({u, vv});
	}

	sort(v.begin(),v.end(),[](pair<int,int>& p1,pair<int,int>& p2)->bool{
		if(p1.second == p2.second){
			return p1.first < p2.first;
		}
		return p1.second < p2.second;
	});
	vector<pair<int,int>> ans;
	ans.push_back(v[0]);
	for(int i =1;i<v.size();i++){
		int x = ans[ans.size()-1].second;
		int m = v[i].first;
		int n = v[i].second;
		if(m>=x){
			ans.push_back({m, n});
			// debug(m,n);
		}
	}
	cout << ans.size() << endl;

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