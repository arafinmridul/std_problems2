#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1701C schedule_management

const int N = 2e5+7;
int a[N];
int n,m;

bool check(int x){
    int rem = 0;
    for(int i=1; i<=n; ++i){
        if(x == a[i])
            continue;
        if(x < a[i])
            rem += a[i]-x;
        if(x > a[i])
            rem -= (x-a[i])/2;
    }
    return rem <= 0;
}

void solve(){
    cin >> n >> m;
    for(int i=1; i<=m; ++i){
        a[i] = 0;
    }
    for(int i=0; i<m; ++i){
        int x; cin>>x;
        ++a[x];
    }
    int ans = 0;
    int l = 1, r = 2*m;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
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