#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1282 B1 B2 K_for_price_of_one

void solve(){
    int n,p,k; cin>>n>>p>>k;
    int a[n];
    for(auto &e:a) cin >> e;
    sort(a,a+n);
    int ans = 0;
    for(int i=0; i<k; ++i){
        int curr = p;
        if(curr < a[i])
            break;
        ans = max(ans,i+1);
        for(int j=i+k-1; j<n; j+=k){
            if(curr < a[j])
                break;
            ans = max(ans,j+1);
            curr -= a[j];
        }
        p -= a[i];
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