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

int n;	
vector<int> v,fTree;

int read(int idx){
	int sum = 0;
	while(idx>0){
		sum += fTree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

int rangeQuery(int l,int r){
	int l_sum = read(l-1);
	int r_sum = read(r);

	return (r_sum - l_sum);
}


void update(int idx, int val){
	while(idx<=n){
		fTree[idx]+=val;
		idx += (idx & -idx);
	}
}

void solve()
{
	cin>>n;
	fTree.resize(n+1,0);
	v.resize(n+1,0);
	fTree[0] = -1; //dummy
	for(int i =1; i<=n;i++){
		cin>>v[i];
		update(i,v[i]);
	}
	int q;cin>>q;
	// {update, U, {idx,val}}
	// {rangeQuery, Q, {l,r}}
	for(int i =0;i<q;i++){
		char temp;
		cin>>temp;
		if(temp == 'U'){
			int idx,val;
			cin>>idx>>val;
			update(idx,val);
		}
		else if(temp == 'Q'){
			int l,r;cin>>l>>r;
			cout<<rangeQuery(l,r)<< endl;
		}
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