#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1644C sub_array_sums

void solve(){
    int n,x; cin>>n>>x; int a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    //for max sum of each length
    vector<int> v(n+1,INT_MIN);
    v[0] = 0;
    for(int i=0; i<n; ++i){
        int temp = 0;
        for(int j=i; j<n; ++j){
            temp += a[j];
            v[j-i+1] = max(v[j-i+1],temp);
        }
    }
    //max sums after incrementing
    for(int k=0; k<=n; ++k){
        int mx = 0;
        for(int l=0; l<=n; ++l){
            int sum = v[l] + min(l,k)*x;
            mx = max(mx,sum);
        }
        cout << mx << ' ';
    }
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}