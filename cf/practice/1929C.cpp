#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll k, x, a; cin >> k >> x >> a;

    // current conseq loss count = c
    // put in k^c coins?
    // >> 2 4 5
    // >> 1 2 2 3 
    ll loss = 0;
    // 1 
    // need * k - need > loss
    // need(k - 1) > loss

    for(int i = 0; i <= x; i++){
        ll needed = (loss / (k - 1)) + 1;
        //cout << loss << ' ' << needed << '\n';
        loss += needed;
        if(a >= needed) a -= needed;
        else{
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
