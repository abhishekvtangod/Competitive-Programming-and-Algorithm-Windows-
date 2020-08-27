/**
 *    author:  abhishekvtangod
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
// struct inventory {
// 	ll quantity=0;
// 	float cost=0.00;
// };
// map<string,inventory> inven_map;

map<string,pair<ll,double>> inven_map;
map<string,ll> cart;
// {quantity,cost}


void solve(){
	inven_map.clear();
	cart.clear();
		
	while(1){
		string str;
		getline(cin,str);
		if(str=="END"){
			return;
		} else if(str==""){
			continue;
		}
		stringstream ss(str);
		string temp;
		vector<string> v;
		while(ss >> temp){
			v.push_back(temp);
		}
		// debug(str);
		if(v[1] == "SM"){

			string cmd = v[2];
			if(v[2] == "ADD"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "-1" << endl;continue;
				}
				double quan = stod(v[4]);
				if(quan <=0 || (ceil(quan) != floor(quan) || inven_map[name].first>0)){
					cout << "-1" << endl;
					continue;
				}
				inven_map[name].first = (ll)quan;
				cout << (ll)inven_map[name].first << endl;
			} else if(v[2] == "REMOVE"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "-1" << endl;continue;
				}
				if(inven_map[name].first <=0){
					cout << "-1" << endl;
					continue;
				}
				inven_map[name].first = 0;
				cout << "1" << endl;

			} else if(v[2] == "GET_QTY"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "0" << endl;continue;
				}
				ll quan = inven_map[name].first;
				if(quan <0){
					cout << "0" << endl;continue;
				}
				cout << quan << endl;
			} else if(v[2] == "INCR"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "-1" << endl;continue;
				}
				double quan = stod(v[4]);
				ll curr = inven_map[name].first;
				if(quan <= 0 || curr<=0 || (ceil(quan) != floor(quan))){
					cout << "-1" << endl;
					continue;
				}
				inven_map[name].first += (ll)quan;
				cout << (ll)quan << endl;
			} else if(v[2] == "DCR"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "-1" << endl;continue;
				}
				double quan = stod(v[4]);
				ll curr = inven_map[name].first;
				if(quan <= 0 || curr-quan<0 || curr <=0 ||(ceil(quan) != floor(quan))){
					cout << "-1" << endl;
					continue;
				}
				inven_map[name].first -= (ll)quan;
				cout << (ll)quan << endl;
			} else if(v[2] == "SET_COST"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "-1" << endl;continue;
				}
				double cst = stod(v[4]);
				if(cst <=0){
					cout << "-1" << endl;
					continue;
				}
				inven_map[name].second = cst;
				cout << fixed << setprecision(1) << cst << endl;
			}
		} else if(v[1] == "S"){
			string cmd = v[2];
			if(v[2] == "ADD"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "-1" << endl;continue;
				}
				double quan = stod(v[4]);
				if(quan <=0 || (ceil(quan) != floor(quan) || cart[name]>0)){
					cout << "-1" << endl;
					continue;
				}
				cart[name] = quan;
				cout << cart[name] << endl;
			} else if(v[2] == "REMOVE"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "-1" << endl;continue;
				}
				if(cart[name] <=0){
					cout << "-1" << endl;
					continue;
				}
				cart[name] = 0;
				cout << "1" << endl;

			} 
			else if(v[2] == "GET_ORDER_AMOUNT"){
				string a="SHOE",b="SHIRT";
				double amt = inven_map[a].second*cart[a] + inven_map[b].second*cart[b];
				if(amt == 0){
					cout <<"-1"<<endl;continue;
				}
				cout << fixed << setprecision(2) << amt  << endl;
			} 
			else if(v[2] == "INCR"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "-1" << endl;continue;
				}
				double quan = stod(v[4]);
				ll curr = cart[name];
				if(quan <= 0 || curr<=0 || ((ceil(quan) != floor(quan)))){
					cout << "-1" << endl;
					continue;
				}
				cart[name] += (ll)quan;
				cout << (ll)quan << endl;
			} else if(v[2] == "DCR"){
				string name = v[3];
				if(name != "SHIRT" && name != "SHOE"){
					cout << "-1" << endl;continue;
				}
				double quan = stod(v[4]);
				ll curr = cart[name];
				if(quan <= 0 || curr-quan<0 || curr <=0 || (ceil(quan) != floor(quan))){
					cout << "-1" << endl;
					continue;
				}
				cart[name] -= (ll)quan;
				cout << (ll)quan << endl;
			}
		}


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
	while(t--){
		solve();
	}

    return 0;
}