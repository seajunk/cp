#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    ll curr = 0;
    ll ans = 0;
    ll seen = false;

    for(int i = 0; i < n; i++){
        if(a[i] == 1) seen = true;

        if(seen && a[i] == 0) curr++;
        if(seen && a[i] == 1) ans = curr;

    }

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
