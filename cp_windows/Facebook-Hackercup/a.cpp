/**
 *    author:  abhishekvtangod
 *    created: 
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

// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

void solve(){
	int n;
	cin >> n;
	string in, out;
	cin >> in >> out;
	for(int i = 0 ; i < n; i++){
		int j = i+1;
		int k = i-1;	
		vector<bool> v(n);
		if(out[i]=='N'){
			for(int jj =0;jj<n;jj++){
				if(jj == i){
					cout << 'Y';
				} else{
					cout << 'N';
				}
			}
			// cout << "hi" << endl;
		} else{
			vector<char> v;
			while(k>=0 && out[k] != 'N' && in[k] != 'N'){
				// cout << "Y";
				v.push_back('Y');
				k--;
			}
			if(k>=0 && in[k] == 'N'){
				v.push_back('N');
				// cout << 'N';
			} 
			else if(k>=0){
				v.push_back('Y');
				// cout << 'Y';
			}
			k--;
			while(k>=0){
				v.push_back('N');
				// cout << 'N';
				k--;
			}	
			for(int ii = v.size()-1;ii>=0;ii--){
				cout << v[ii];
			}
			cout << 'Y';

			while(j<n && out[j] != 'N' && in[j] != 'N'){
				cout << "Y";
				j++;
			}
			if(j<n && in[j] == 'N'){
				cout << 'N';
			} else if(j<n){
				cout << 'Y';
			}
			j++;
			while(j<n){
				cout << 'N';
				j++;
			}
		}
		cout << endl;
	}

}

int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif 

	ll t;cin>>t;
	int i = 1;
	while(t--){
		cout << "Case #"<<i<<":" << endl;
		solve();
		i++;
	}

    return 0;
}