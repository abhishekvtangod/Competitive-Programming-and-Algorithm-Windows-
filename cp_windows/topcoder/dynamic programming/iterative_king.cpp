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


// Question : What is the optimal solution for the first k chests
// chest1,chest2,chest3 ... chestk
// value1,value2,value3 ... valuek
// choose chests such that they shouldn't be adjacent to each other and sum of values should be maximum

const int mxN = 1e5+5;
int dp[mxN];
vector<int> v;


int opt(int k){
	int ans;
	for(int i=0;i<=k;i++){

		if(i<=0){
			ans = 0;
		}
		else if(i==1){
			ans = v[i-1];
		}
		else{
			int excl = dp[i-1];
			int incl = dp[i-2] + v[i-1];
			ans = max({incl,excl});
			
		}
		dp[i] = ans;

	}
	// for(int i =0;i<=k;i++){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<< endl;
	return dp[k];
}

// 5
// 100 4 7 90 13


void solve()
{
	int n;cin>>n;
	v.clear();
	for(int i =0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}

	cout<<opt(n)<< endl;

}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	// ll t;cin>>t;
	// while(t--)
	// {
		solve();
	// }
	

    return 0;
}