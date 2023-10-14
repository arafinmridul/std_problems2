#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

// blew my head off!
//CF 1875C jellyfish_green_apple

void solve(){
    int n,m; cin>>n>>m;
    int ans = 0;
    for(int i=1; i<=33; ++i){
        if(n%m == 0){
            cout << ans << nl;
            return;
        }
        ans += (n%m);
        n = (n%m)*2;
    }
    cout << -1 << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}