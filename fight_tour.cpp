#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1719C fighting_tournament

void solve(){
    int n,q; cin>>n>>q;
    vector<int> wins[n];
    int prev,idx=0; cin>>prev;
    for(int i=1; i<n; ++i){
        int x; cin>>x;
        if(x > prev)
            idx = i,prev = x;
        wins[idx].push_back(i);
    }
    while(q--){
        int id,round; cin>>id>>round;
        --id;
        if(round > n-1){
            if(wins[id].size() and wins[id].back() == n-1)
                cout << wins[id].size()+round-n+1 << nl;
            else
                cout << wins[id].size() << nl;
            continue;
        }
        int ans = upper_bound(wins[id].begin(),wins[id].end(),round)-wins[id].begin();
        cout << ans << nl;
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