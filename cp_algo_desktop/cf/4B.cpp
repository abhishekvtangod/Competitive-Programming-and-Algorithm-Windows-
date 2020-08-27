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
	int d,tm;
	cin>>d>>tm;
	vector<pair<int,int>> v(d);
	int mn = 0, mx = 0;
	int one=0;
	for(int i =0;i<d;i++){
		int l,r;
		cin>>l>>r;
		v[i] = {l,r};
		mn += l;
		mx += r;
		if(l-r >=1){
			one++;
		}

	}



	if(tm<(mn) || tm>(mx)){
		cout<<"NO"<< endl;
		return;
	}
	cout<<"YES"<< endl;
	vector<int> ans(d);
	for(int i=0;i<d;i++){
		ans[i] = (v[i].first);
	}

	int total = tm-mn;

	for(int i=0;i<d;i++){
		int cap = v[i].second-v[i].first;
		// cout<<ans[i]<<" "<<cap<<endl;

		if(total>=cap){
			ans[i]+=cap;
			total-=cap;
		}
		else{
			ans[i]+=total;
			break;			
		}
	}
	for(int i:ans){
		cout<<i<<" ";
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
	// while(t--)
	// {
		solve();
	// }
	

    return 0;
}