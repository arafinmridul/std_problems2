#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

//CF 1844D row_major

void solve(){
    int n; cin>>n;
    vector<int> factors = {1};
    for(int i=2; i*i<=n; ++i){
        if(n%i == 0){
            factors.push_back(i);
            factors.push_back(n/i);
        }
    }
    sort(factors.begin(),factors.end());
    string ans = "a";
    for(int i=1; i<n; ++i){
        for(char j='a'; j<='z'; ++j){
            bool f = true;
            for(auto e:factors){
                if(i-e < 0) break;
                if(ans[i-e] == j){
                    f = false; break;
                }
            }
            if(f){
                ans += j; break;
            }
        }
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