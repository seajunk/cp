#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll a, b; cin >> a >> b;
    if(a >= b) cout << a << '\n';
    else{
        cout << max(a - (b - a), 0ll) << '\n';
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
