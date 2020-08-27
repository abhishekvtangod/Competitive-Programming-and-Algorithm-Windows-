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

int subseq(string a, string b){
	int j = 0;
	int cnt =0;
	int n = a.size(), m = b.size();
	for(int i=0;i < n;i++){
		if(a[i] != '0'){
			cnt++;
		}
		if(a[i] == b[j] && (j < m)){
			j++;
		}

	}z
	if(cnt == m && j == m){
		return 2;
	}
	return (j==m);

}

void solve(){
	string a,b;
	cin >> a >> b;
	int n = a.size();
	vector<int> v;
	for(int i = 0; i < n ; i++){
		int t;
		cin >> t;
		v.push_back(t-1);
	}
	for(int i = 0; i < n; i++){
		// cout << a << endl;
		int temp = subseq(a,b);
		if(temp == 0){
			cout << i-1 << endl;
			return;
		}
		else if(temp == 2){
			cout << i << endl;
			return;
		}
		else{
			a[v[i]] = '0';
		}
	}
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