#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//this implementation problem!
//CF 1705C mark_his_unfinished_essay

void solve(){
    int n,c,q; cin>>n>>c>>q;
    string s; cin>>s;
    vector<int> start(c+1), diff(c+1);
    int prev = n;
    for(int i=1; i<=c; ++i){
        int l,r; cin>>l>>r;
        --l, --r;
        start[i] = prev;
        prev += r-l+1;
        diff[i] = start[i]-l;
    }
    while(q--){
        int idx; cin>>idx;
        --idx;
        for(int i=c; i>=1; --i){
            if(idx < start[i])
                continue;
            idx -= diff[i];
        }
        cout << s[idx] << nl;
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