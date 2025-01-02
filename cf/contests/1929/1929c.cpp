#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll k, x, a; cin >> k >> x >> a;

    // lose x in a row, win once -> profit?
    
    // in x + 1 turns, lose xc coins, gain k*remaining coins, net = kc - xc

    if(k - x < 1){
        cout << "NO\n";
        return;
    }

    if(a <= x){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
