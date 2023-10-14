#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1513B and_sequences

const int mod = 1e9+7;

void solve(){
    int n; cin>>n; int a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    unordered_set<int> s;
    for(int i=0; i<31; ++i){
        int bit = 1<<i;
        vector<int> tmp;
        for(int j=0; j<n; ++j){
            if(a[j]&bit)
                tmp.push_back(j);
        }
        if(tmp.size() == n-1){
            cout << 0 << nl;
            return;
        }
        if(tmp.size() and tmp.size() <= n-2){
            for(auto &e:tmp)
                s.insert(e);
            tmp.clear();
        }
    }
    int ok = n - s.size();
    int ans = (ok*(ok-1))%mod;
    for(int i=2; i<=n-2; ++i){
        ans = (ans*i)%mod;
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