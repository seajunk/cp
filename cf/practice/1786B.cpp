#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, w, h; cin >> n >> w >> h;
    ll a[n], b[n];

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];


    ll lshift = LLONG_MIN, rshift = LLONG_MAX;

    for(int i = 0; i < n; i++){
        lshift = max(lshift, (b[i] + h) - (a[i] + w));
        rshift = min(rshift, (b[i] - h) - (a[i] - w));
    }

    if(lshift <= rshift){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
