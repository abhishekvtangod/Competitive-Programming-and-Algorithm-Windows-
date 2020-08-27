/**
 *    author:  abhishekvtangod
 *    created: 
**/
#undef _GLIBCXX_DEBUG
#undef _ABHI
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
#define pi 3.14159265358979323846 
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
long double dist(double lt1,double lg1,double lt2,double lg2){
    lt1 = ((pi / 180) * lt1); 
    lg1 = ((pi / 180) * lg1);
    lt2 = ((pi / 180) * lt2);
    lg2 = ((pi / 180) * lg2);
    
    // Haversine Formula 
    long double dLg = lg2 - lg1; 
    long double dLt = lt2 - lt1; 
    long double ans  = pow(sin(dLt / 2), 2);
    
    ans += cos(lt2)*cos(lt1)*pow(sin(dLg / 2), 2); 
    ans = 2 * asin(sqrt(ans))*6371;   
    return ans*ans; 
}

void solve()
{   
    int n,t1;cin>>n;
    double t;
    vector<double> lt(n), lg(n);
    vector<int > ht(n);
    for(int i=0;i<n;i++){
    	cin >> lt[i];
    }

    for(int i=0;i<n;i++){
    	cin >> lg[i];
    }

    for(int i=0;i<n;i++){
    	cin >> ht[i];
    }

    double currLat, currLong;
        cin>>currLat>>currLong;
    int ans=0;
    for(int i=0;i<n;i++){

        long double d=dist(lt[i],lg[i],currLat,currLong);
        long double range=2*6371*ht[i]+ht[i]*ht[i];
        if(d<=range)ans++;
        debug(range, d);

    }
    cout<<ans;
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
		solve();
	// }

    return 0;
}