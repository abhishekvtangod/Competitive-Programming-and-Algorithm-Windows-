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
	ll h,n;
	cin>>h>>n;
	string q;
	cin>>q;
	ll th = 2*h-1;
	ll area = (th*th+1) / 2; //ceil
	// cout<<area<<endl;
	string s="";

	for(int i =0;i<area;i++){
		s+=(q[i%n]);
	}
	// cout<<s<<endl;

	// for(int i =0;i<h;i++){
		// for(int j =0;j<h;j++){
		// 	int space = th/2-j;
		// 	for(int k = 0;k <space;k++){
		// 		cout<<" ";
		// 	}
		// 	int idx = h-1-j;
		// 	for(int cnt = 1;cnt <= (th-space*2);cnt++){
		// 		cout<<s[idx];
		// 		idx+=1;
		// 	}
		// 	cout<<endl;
		// }
	// }

	int arr[th][th];
	memset(arr,-1,sizeof(arr));
	int idx = 0;
	
	for(int last = h-1;last>=0;last--){
		int j = abs(last-(h-1));
		int i = h-1;
		for(;i>=(h-1)-last;i--){
			arr[i][j++] = idx++;
		}
		i+=2;
		// j-=2;
		for(;i<h;i++){
			// cout<<i<<" "<<j++<<endl;		
			arr[i][j++] = idx++;
		}
		// cout<<i<<"-"<<j<<endl;		
		j-=2;
		for(;j>=h-1;j--){
			// cout<<i++<<" "<<j<<endl;
			arr[i++][j] = idx++;
		}
		i-=2;
		// cout<<i<<"-"<<j<<endl;
		for(;i>h-1;i--){
			// cout<<i<<" "<<j--<<endl;
			arr[i][j--] = idx++;

		}
	}
	for(int i =0;i<th;i++){
		for(int j =0;j<th;j++){
			if(arr[i][j] == -1){
				cout<<" ";
				continue;
			}
			cout<<s[arr[i][j]];;
		}
		cout<<endl;
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