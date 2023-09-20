#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1696C fishing_price

void solve(){
    int n,m; cin>>n>>m; int a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    int k; cin>>k; int b[k];
    for(int i=0; i<k; ++i){
        cin >> b[i];
    }
    vector<pair<int,int>> a_mod,b_mod;
    for(int i=0; i<n; ++i){
        int curr = 1;
        while(a[i] % m == 0){
            a[i] /= m;
            curr *= m;
        }
        if(i and a[i] == a_mod.back().first){
            a_mod.back().second += curr;
        }
        else a_mod.push_back({a[i],curr});
    }
    for(int i=0; i<k; ++i){
        int curr = 1;
        while(b[i] % m == 0){
            b[i] /= m;
            curr *= m;
        }
        if(i and b[i] == b_mod.back().first){
            b_mod.back().second += curr;
        }
        else b_mod.push_back({b[i],curr});
    }
    if(a_mod != b_mod)
        cout << "NO\n";
    else
        cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}