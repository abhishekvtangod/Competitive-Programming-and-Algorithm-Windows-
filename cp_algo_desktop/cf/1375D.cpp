
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

int mex(vector<int> v){
	set<int> s;
	for(int i =0;i<v.size();i++){
		s.insert(v[i]);
	}
	vector<int> ans(s.begin(),s.end());
	int i =0;
	for(i =0;i<ans.size();i++)
	{
		if(ans[i] != i){
			return i;
		}
	}
    return i;
}

void solve(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i =0;i<n;i++){
		int t;cin>>t;
		v.push_back(t);
	}
	for(int i =0;i<n;i++){
		int temp = mex(v);

		v[temp] = temp;
	}
	for(auto u:v){
		cout<<u<<" ";
	}
	cout<<endl;
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