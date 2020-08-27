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



// sqrt decompostion  - finding sum of elements in the range

void solve(){
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	int len = (int)sqrt(n+.0)+1;
	vector<int> b(len, 0);


	for(int i = 0 ;i< n; i++){
		cin >> a[i];
	}

	//preprocess
	for(int i = 0; i<n;i++){
		b[i/len] += a[i];
	}

	//answering the queries
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;

		int sum = 0;
		for(int i = l; i<=r;){
			if(i % len == 0 && i + len - 1 <= r){
				sum+=b[i/len];
				i+=len;
			}else{
				sum += a[i];
				i++;
			}
		}

		cout << sum << endl;
	}


}

void solve1(){
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	int len = (int)sqrt(n+.0)+1;
	vector<int> b(len, 0);


	for(int i = 0 ;i< n; i++){
		cin >> a[i];
	}

	//preprocess
	for(int i = 0; i<n;i++){
		b[i/len] += a[i];
	}

	//answering the queries
	// reducing divsion opetaions which is costly
	for(int i =0 ; i < q; i++){
		int l, r;
		cin >> l >> r;

		int sum = 0;
		int c_l = l/len, c_r = r/len;
		if(c_l == c_r){
			for(int i = l;i<=r;i++){
				sum += a[i];
			}
		} else{

			for(int i = l; i <= (c_l+1)*len-1;i++){
				sum += a[i];
			}
			for(int i = c_l + 1; i< = c_r-1; i++){
				sum += b[i];
			}
			for(int i = c_r * len; i<=r ; i++){
				sum += a[i];
			}


		}

		cout << sum << endl;


	}



}

int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif 

	// ll t;cin>>t;
	// while(t--){
		solve1();
	// }

    return 0;
}