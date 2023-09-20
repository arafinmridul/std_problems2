#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1721C min_max_array_transformation

void solve(){
    int n; cin>>n; int a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    multiset<int> b,rmv;
    for(int i=0; i<n; ++i){
        int x; cin>>x;
        b.insert(x);
    }
    int ans[2][n];
    for(int i=n-1; i>=0; --i){
        auto hi = b.end(); hi--;
        ans[1][i] = *hi - a[i];
        auto lo = b.lower_bound(a[i]);
        ans[0][i] = *lo - a[i];
        if(i){
            rmv.insert(a[i]);
            auto temp = b.lower_bound(a[i-1]);
            if(lo != temp){
                for(auto e:rmv)
                    b.erase(b.lower_bound(e));
                rmv.clear();
            }
        }
    }
    for(int i=0; i<2; ++i){
        for(int j=0; j<n; ++j)
            cout << ans[i][j] << ' ';
        cout << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}