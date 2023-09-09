#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1415C bouncing_ball

void solve(){
    int n,p,k,x,y; string s; cin>>n>>p>>k>>s>>x>>y;
    int cost[n];
    int curr = 0;
    for(int i=n-1; i>=n-k; --i){
        curr = 0;
        for(int j=i; j>=0; j-=k){
            if(s[j] == '0')
                curr += x;
            cost[j] = curr;
        }
    }
    int ans = LONG_LONG_MAX;
    curr = 0;
    for(int i=p-1; i<n; ++i){
        int temp = cost[i]+curr;
        ans = min(ans,temp);
        curr += y;
    }
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}