#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1276A twone_one_two

void solve(){
    string s; cin>>s;
    int n = s.size();
    vector<int> rmv;
    for(string st:{"twone","two","one"}){
        for(int pos=0; (pos=s.find(st,pos)) != string::npos;){
            s[pos + st.size()/2] = 'X';
            rmv.push_back(pos + st.size()/2 + 1);
        }
    }
    cout << rmv.size() << nl;
    for(auto e:rmv)
        cout << e << ' ';
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