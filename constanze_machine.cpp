#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1245C constanze_machine

const int N = 1e5+5;
int dp[N];
int mod = 1e9+7;

void solve(){
    string s; cin>>s;
    int n = s.length();
    if(s.find('m')!=string::npos or s.find('w')!=string::npos){
        cout << 0 << nl;
        return;
    }
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; ++i){
        if(s.substr(i-2,2)=="uu" or s.substr(i-2,2)=="nn"){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        else dp[i] = dp[i-1];
    }
    cout << dp[n] << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}