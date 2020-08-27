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

void solve()
{
	int n,m;cin>>n>>m;
	char arr[n+1][m+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='B'){
				if(arr[i-1][j] == '.' && (i != 0)){
					arr[i-1][j] = '#';
				}
				if(arr[i+1][j] == '.' && (i != n-1)){
					arr[i+1][j] = '#';
				}
				if(arr[i][j-1] == '.' && (j != 0)){
					arr[i][j-1] = '#';
				}
				if(arr[i][j+1] == '.' && (j != n-1)){
					arr[i][j+1] = '#';
				}
				
			}	
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			dp[i][j] = 
		}
		cout<< endl;
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
	while(t--)
	{
		solve();
	}
	

    return 0;
}