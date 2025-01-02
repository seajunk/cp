#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll curr = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        curr += a[i];
        for(int j = 1; j <= curr; j++){
            if(j*j == curr && (curr % 2 == 1)){
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
