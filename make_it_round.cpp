#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1759D make_it_round

void solve(){
    int n,m; cin>>n>>m;
    int nf = n;
    int ans = 1;
    int five=0, two=0;
    while(nf % 5 == 0)
        nf /= 5, ++five;
    while(nf % 2 == 0)
        nf /= 2, ++two;
    while(five > two and ans*2 <= m)
        ans *= 2, --five;
    while(two > five and ans*5 <= m)
        ans *= 5, --two;
    while(ans*10 <= m)
        ans *= 10;
    n *= ans;
    for(int i=9; i>=1; --i){
        if(ans*i <= m){
            cout << n*i << nl;
            return;
        }
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