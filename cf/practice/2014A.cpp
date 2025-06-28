#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    ll r = 0;

    for(int i = 0; i < n; i++){
        if(a[i] >= k){
            r += a[i];
            a[i] = 0;
        }
        else if(a[i] == 0){
            if(r > 0){
                r--;
                ans++;
            }
        }
    }

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
