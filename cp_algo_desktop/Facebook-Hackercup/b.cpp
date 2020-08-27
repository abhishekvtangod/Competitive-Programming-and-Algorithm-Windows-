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

string a = "Y", b = "N";
void solve(){
	int n;
	cin >> n;
	string ss;
	cin >> ss;
	vector<int> s(n);
	for(int i =0;i<n;i++){
		if(ss[i] == 'A'){
			s[i]= 1;
		} else{
			s[i] = 0;
		}
	}
	if(n==1){
		cout << a << endl;
		return;
	}

	vector<int> v;
	v.push_back(s[0]);
	v.push_back(s[1]);
	for(int i = 2;i<n;i++){
		// cout << "hi" << endl;
		int x = s[i];
		int j = v.size();
		if(j ==1){
			v.push_back(x);
		} 
		else{
			int y = v[j-1];
			int z = v[j-2];
			if(x == y && y == z){
				v.push_back(x);continue;
			} else{
				v.pop_back();
				v.pop_back();
				int one=0, zero=0;
				(x==1)?(one++):(zero++);
				(y==1)?(one++):(zero++);
				(z==1)?(one++):(zero++);
				// cout << x << " " << y << " " << z << endl;
				if(one>zero){
					v.push_back(1);
				} else{
					v.push_back(0);
				}
			}

		}
	}
	// cout << v.size() << endl;
	if(v.size() == 1){
		cout << a << endl;
	} else{
		cout << b << endl;
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
		cout << "Case #"<<i<<": ";
		solve();
		i++;
	}

    return 0;
}