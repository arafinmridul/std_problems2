#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1847C vampiric_powers

void solve(){
	int n; cin>>n; int a[n];
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	int max_val = 1<<8; // 256
	vector<bool> has_pref(max_val,false);
	has_pref[0] = true; 
	int curr_xor = 0;
	int ans = 0;
	for(int i=0; i<n; ++i){
		curr_xor ^= a[i];
		for(int val=0; val<max_val; ++val){
			if(has_pref[val] == true){
				ans = max(ans, val^curr_xor);
			}
		}
		has_pref[curr_xor] = true;
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