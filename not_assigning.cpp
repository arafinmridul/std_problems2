#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1627C not_assigning

int n;
const int N = 1e5+7;
bool vis[N];
vector<int> vertex[N];
vector<map<int,int>> ans(N);

void DFS(int idx, int p){
    vis[idx] = true;
    for(auto e:vertex[idx]){
        if(vis[e] == false){
            ans[idx][e] = ans[e][idx] = (p ? 2 : 3);
            DFS(e, p^1);
        }
    }
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        vis[i] = false;
        vertex[i].clear();
        ans[i].clear();
    }
    vector<pair<int,int>> stem(n-1);
    for(int u,v,i=1; i<n; ++i){
        cin >> u >> v;
        vertex[u].push_back(v);
        vertex[v].push_back(u);
        stem[i-1] = {u,v};
    }
    int first_node = -1;
    for(int i=1; i<=n; ++i){
        if(vertex[i].size() > 2){
            cout << -1 << nl;
            return;
        }
        if(vertex[i].size() == 1)
            first_node = i;
    }
    DFS(first_node,1);
    for(auto [i,j]:stem)
        cout << ans[i][j] << ' ';
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