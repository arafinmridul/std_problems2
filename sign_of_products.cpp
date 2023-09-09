#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1215B sign_of_products

void solve(){
    int n; cin>>n; int a[n+1];
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    int dp[n+1][2]; dp[0][0] = dp[0][1] = 0;
    for(int i=1; i<=n; ++i){
        if(a[i] > 0){
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = dp[i-1][1];
        }
        else{
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + 1;
        }
    }
    int pos = 0, neg = 0;
    for(int i=1; i<=n; ++i){
        pos += dp[i][0];
        neg += dp[i][1];
    }
    cout << neg << ' ' << pos << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}