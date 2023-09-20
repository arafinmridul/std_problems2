#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1728C digital_logarithm

int go(int x){
    int res = 0;
    for(; x; x/=10)
        ++res;
    return res;
}

void solve(){
    int n; cin>>n;
    priority_queue<int> a,b;
    for(int i=0; i<n; ++i){
        int x; cin>>x;
        a.push(x);
    }
    for(int i=0; i<n; ++i){
        int x; cin>>x;
        b.push(x);
    }
    int ans = 0;
    while(a.empty() == 0){
        if(a.top() == b.top()){
            a.pop();
            b.pop();
            continue;
        }
        if(a.top() > b.top()){
            int temp = go(a.top());
            a.pop();
            a.push(temp);
        }
        else{
            int temp = go(b.top());
            b.pop();
            b.push(temp);
        }
        ++ans;
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