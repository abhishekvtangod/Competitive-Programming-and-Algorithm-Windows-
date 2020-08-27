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
	int n,k;
	cin >> n >> k;
	vector<int> a,b;
	for(int i = 0 ; i < n ; i++){
		int t;
		cin >> t;
		a.push_back(t);
	}
	for(int i = 0 ; i < n ; i++){
		int t;
		cin >> t;
		b.push_back(t);
	}
	vector<pair<int,int>> v;
	ll ans = 0,cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] < b[i]){
			ans += a[i];
			// cout<<a[i]<< endl;
			cnt++;
			continue;
		}

		v.push_back({a[i],b[i]});
	}
	sort(v.begin(), v.end(),[](pair<int,int>& p1, pair<int,int>& p2)->bool{
		int a = p1.first;
		int b = p1.second;
		int x = p2.first;
		int y = p2.second;
		
		return (a - b) < (x - y);

	});
	auto it = v.begin();
	int i = cnt;
	for(; i <k ;i++){
		ans += it->first;
		// cout << it->first << endl;
		it++;
	}
	while(it != v.end()){
		ans += it->second;
		// cout << it->second << endl;
		it++;
	}

	cout << ans << endl;

}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	// ll t;cin>>t;
	// while(t--){
		solve();
	// }
	

    return 0;
}