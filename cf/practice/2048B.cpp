#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    
    vector<ll> ans(n, -1);

    ll curr = 1;
for(int i = k - 1; i < n; i =  min(k + i, n - 1)){
        ans[i] = curr;
        curr += 1;
        if(i == n - 1) break;
    }

    for(int i = 0; i < n; i++){
        if(ans[i] == -1){
            ans[i] = curr;
            curr += 1;
        }
    }

    for(ll e : ans) cout << e << ' ';
    cout << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
