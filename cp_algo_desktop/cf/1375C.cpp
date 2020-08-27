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
	int n; 
	cin>>n;
	string a = "YES", b = "NO";
	vector<int> v;
	for(int i =0;i<n;i++){
		int t;cin>>t;
		v.push_back(t);
	}
	if(n==1){
		cout<<a<<endl;
		return;
	}
	// int mx = v[0];
	// for(int i =0;i<n-1;i++){
	// 	int curr  = v[i];
	// 	mx = min({mx,curr});
	// 	while(v[i]<v[i+1]){
	// 		i++;
	// 	}
	// }
	// int i = n-1;
	// while(i-1>=0 && v[i-1] <v[i]){
		
	// }
	if(v[0] < v[n-1]){
		cout<<a<<endl;
	}
	else{
		cout<<b<<endl;
	}

}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	ll t;cin>>t;
	while(t--){
		solve();
	}
	

    return 0;
}