#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{   

    ll n, k;
    cin >> n >> k;
    // vector<int> v(n);
    multiset <ll>  s;
    for(int i =0;i<n;i++){
        // cin >> v[i];
        int t;
        cin >> t;
        s.insert(t);
    }

    while(k){
        k--;
        ll mx = *s.rbegin();
        // cout << mx << endl;
        // s.erase(mx);
        s.erase((--s.end()));

        s.insert(ceil(mx/2));
    }
    ll ans = 0;
    for(auto &u:s){
        // cout << u << " ";
        ans+=u;
    }
    // cout << endl;
    cout << ans ;


    return 0;
}