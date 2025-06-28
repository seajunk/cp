#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // if max is first element <=> array is vulnerable

    ll ans = LLONG_MAX;

    for(int i = 0; i < n; i++){
        // how many guys to delete to make a[i] left most element & max of a 
        ll count = 0;
        for(int j = i + 1; j < n; j++){
            if(a[j] > a[i]) count++;
        }
        ans = min(i + count, ans);
    }
    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
