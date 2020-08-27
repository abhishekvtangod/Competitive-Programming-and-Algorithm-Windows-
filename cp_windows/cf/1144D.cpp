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
	int n;cin>>n;
	vector<int> v(n+1);
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		mp[v[i]]++;
	}
	ll mxVal = v[0];
	ll mxCnt = 0;
	for(auto u :mp){
		if(u.second>mxCnt){
			mxVal = u.first;
			mxCnt = u.second;
		}
	}
	ll mxPos = 0;
	for(int i=1;i<=n;i++){
		if(v[i] == mxVal){
			mxPos = i;break;
		}
	}
	cout<<n-mp[mxVal]<< endl;

	for(int i = mxPos-1;i>=1;i--){
		if(v[i]<mxVal){
			cout<<"1 ";
		}
		else{
			cout<<"2 ";

		}
		cout<<i<<" "<<i+1<<endl;		

	}
	for(int i=mxPos+1;i<=n;i++){
		if(v[i]==mxVal){
			continue;
		}

		if(v[i]<mxVal){
			cout<<"1 ";
		}
		else{
			cout<<"2 ";

		}
		

		cout<<i<<" "<<i-1<<endl;		

	}


}

// 5
// 11 2 8 8 10


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