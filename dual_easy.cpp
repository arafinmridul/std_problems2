#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1854 A1 dual_easy
//making each element either positive or negative
//by finding out the largest pos and neg number
//then traversing the array from left to right or right to left as needed

void solve(){
    int n; cin>>n; int a[n];
    int lp = 0, ln = 0;
    int pi = -1, ni = -1;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(a[i] >= lp){
            pi = i;
            lp = a[i];
        }
        if(a[i] <= ln){
            ni = i;
            ln = a[i];
        }
    }
    int idx = (lp>=abs(ln)) ? pi : ni;
    cout << n + n - 1 << nl;
    for(int i=0; i<n; ++i)
        cout << i+1 << ' ' << idx+1 << nl;
    if(lp >= abs(ln)){
        for(int i=2; i<=n; ++i)
            cout << i << ' ' << i-1 << nl;
    }
    else{
        for(int i=n-1; i>0; --i)
            cout << i << ' ' << i+1 << nl;
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