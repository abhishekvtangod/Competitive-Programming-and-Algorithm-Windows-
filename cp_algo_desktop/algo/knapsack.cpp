/**
 *    author:  abhishekvtangod
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


void solve2(){
    int n,W;
    cin>>n>>W;
    int dp[W+2];
    memset(dp,0,sizeof(dp));

    vector<int> val(n+1);
    vector<int> wt(n+1);
    for(int i =1;i<=n;i++){
        cin>>val[i];
    }
    for(int i =1;i<=n;i++){
        cin>>wt[i];
    }   
    for(int i =1;i<=n;i++){
        for(int w = W;w-wt[i]>=0;w--){
                dp[w] = max({dp[w],val[i] + dp[w-wt[i]]}); 
        }
    }
    // for(int i =1;i<=W;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    cout<<dp[W]<<endl;
    
}

void solve1(){
    int n,W;
    cin>>n>>W;
    int dp[n+2][W+2];
    memset(dp,0,sizeof(dp));

    vector<int> val(n+1);
    vector<int> wt(n+1);
    for(int i =1;i<=n;i++){
        cin>>val[i];
    }
    for(int i =1;i<=n;i++){
        cin>>wt[i];
    }
    for(int i =1;i<=n;i++){
        for(int j =1;j<=W;j++){
            if(wt[i]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max({dp[i-1][j],val[i] + dp[i-1][j-wt[i]]});
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j =1;j<=W;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][W]<< endl;

    //backtracking
    int Tval = dp[n][W];
    int Twt = W;
    for(int i =n;Tval>0 && i>=1;i--){
        if(Tval == dp[i-1][Twt]){
            continue;
        }
        else{
            cout<<i<<" ";
            Tval -= val[i];
            Twt -= wt[i];
        }
    }   
    cout<<endl;
}

int opt(int i,int W,int **dp,vector<int> val,vector<int> wt){
    if(i<1){
        return 0;
    }
    if(dp[i][W] != -1){
        return dp[i][W];
    }

    if(wt[i] > W){
        return dp[i][W] = opt(i-1,W,dp,val,wt);
    }
    else{
         dp[i][W] = max({
            opt(i-1,W,dp,val,wt),
            opt(i-1,W-wt[i],dp,val,wt)+val[i]
        });
         return dp[i][W];
    }
}

void solve(){
    int n,W;     
    cin>>n>>W;
    // int **dp = new int[n+2][W+2];
    int **dp;
    dp = new int*[n+2];
    for(int i =0;i<n+2;i++){
        dp[i] = new int[W+2];
    }

    for(int i =0;i<n+2;i++){
        for(int j =0;j < W+2;j++){
            dp[i][j] = -1;
        }
    }
    vector<int> val(n+1);
    vector<int> wt(n+1);
    for(int i =1;i<=n;i++){
        cin>>val[i];
    }
    for(int i =1;i<=n;i++){
        cin>>wt[i];
    }
    cout<<opt(n,W,dp,val,wt)<< endl; 

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
        // solve();
        // solve1();
        solve1();
    // }
    

    return 0;
}