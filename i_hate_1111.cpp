#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1526B I_hate_1111

void solve(){
    int n; cin>>n;
    // 11 and 111
    //CMT says after 11*111 - (11+111), we can write any number in the form of a*11+b*111
    int limit = 11*111 - (11+111);
    if(n > limit){
        cout << "YES\n";
        return;
    }
    int curr = 0;
    for(int i=0; i*11<=n; ++i){
        curr = i*11;
        for(int j=0; j*111<=n; ++j){
            int temp = curr + j*111;
            if(temp == n){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}