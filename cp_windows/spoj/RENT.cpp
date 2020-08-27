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
int latestNonConflict(vector<tuple<int,int,int>> v,int i){
	int a,b,c;
	tie(a,b,c)=v[i-1];
	for(int j=i-1;j>=0;j--){
		int x,y,z;
		tie(x,y,z)=v[j];
		if(y<=a){
			return j;
		}
	}
	return -1;

}

int mxxPr(vector<tuple<int,int,int>> v,int n){
	int a,b,c;
	tie(a,b,c) = v[n-1];
	if(n==1){
		return c;
	}

	//included
	int incl = c;
	int i = latestNonConflict(v,n);
	if(i!=-1){
		incl+=mxxPr(v,i+1);
	}

	//excluded
	int exl  = mxxPr(v,n-1);

	return max({incl,exl});
}



//top-down
void solve()
{
	int n;cin>>n;
	vector<tuple<int,int,int>> v;
	for(int i=0;i<n;i++){
		int s,d,c;
		cin>>s>>d>>c;
		v.push_back({s,s+d,c});
	}
	sort(v.begin(),v.end(),[](tuple<int,int,int>& t1,tuple<int,int,int>& t2)->bool{
		int s1,d1,c1;
		int s2,d2,c2;
		tie(s1,d1,c1)=t1;
		tie(s2,d2,c2)=t2;
		if(d1==d2){
			return s1<s2;
		}
		return d1<d2;
	});
	// for(auto u:v){
	// 	int a,b,c;
	// 	tie(a,b,c)=u;
	// 	cout<<a<<" "<<b<<" "<<c<< endl;
	// }

	cout<<mxxPr(v,n)<< endl;

}
// ----------------------------------------------------------------------------
int latestNonConflictIter(vector<tuple<int,int,int>> v,int i){
	int a,b,c;
	tie(a,b,c)=v[i];
	for(int j=i-1;j>=0;j--){
		int x,y,z;
		tie(x,y,z)=v[j];
		if(y<=a){
			return j;
		}
	}
	return -1;

}

//bottom-up
void solve1(){
	int n;cin>>n;
	vector<tuple<int,int,int>> v;
	for(int i=0;i<n;i++){
		int s,d,c;
		cin>>s>>d>>c;
		v.push_back({s,s+d,c});
	}
	sort(v.begin(),v.end(),[](tuple<int,int,int>& t1,tuple<int,int,int>& t2)->bool{
		int s1,d1,c1;
		int s2,d2,c2;
		tie(s1,d1,c1)=t1;
		tie(s2,d2,c2)=t2;
		if(d1==d2){
			return s1<s2;
		}
		return d1<d2;
	});
	// for(auto u:v){
	// 	int a,b,c;
	// 	tie(a,b,c)=u;
	// 	cout<<a<<" "<<b<<" "<<c<< endl;
	// }
	vector<int> dp(n);
	int t1,t2,t3;
	tie(t1,t2,t3)=v[0];
	dp[0]=t3;
	for(int i=1;i<n;i++){
		int a,b,c;
		tie(a,b,c)=v[i];
		int incl = c;
		int latest = latestNonConflictIter(v,i);
		if(latest !=-1){
			incl+=dp[latest];
		}
		//max of incl and exl
		dp[i] = max({incl,dp[i-1]});
	}
	cout<<dp[n-1]<< endl;

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
		solve1();
	}
	

    return 0;
}