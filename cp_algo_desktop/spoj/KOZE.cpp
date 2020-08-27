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

const int mX = 260;
char arr[mX+2][mX+2];
int visited[mX+2][mX+2];
int n,m;
pair<int,int> dfs(int i,int j){
	if(visited[i][j] || i<0 || i>n-1 || j<0 || j>m-1 || arr[i][j] == '#'){
		return {0,0};
	}
	int w=0,s=0;
	visited[i][j] = 1;
	if(arr[i][j] == 'k'){
		s++;
	}
	else if(arr[i][j] == 'v'){
		w++;
	}
	pair<int,int> a,b,c,d;
	a = dfs(i,j-1);
	b = dfs(i,j+1);
	c = dfs(i-1,j);
	d = dfs(i+1,j);
	int ts = a.first+b.first+c.first+d.first+s;
	int tv = a.second+b.second+c.second+d.second+w;
	return {ts,tv};


}


void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>arr[i][j];
			visited[i][j] = 0;
		}
	}
	pair<int,int> temp;
	int w=0,s=0;
	for(int i = 0 ;i<n;i++){
		for(int j =0 ;j<m;j++){
			if((arr[i][j] == 'k' || arr[i][j] == 'v') && (!visited[i][j])){
				temp = dfs(i,j);
				if(temp.first > temp.second){
					s+=temp.first;
				}
				else{
					w+=temp.second;
				}
			}

		}
	}
	cout<<s<<" "<<w<<endl;


}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	// ll t;cin>>t;
	// while(t--){
		solve();
	// }
	

    return 0;
}