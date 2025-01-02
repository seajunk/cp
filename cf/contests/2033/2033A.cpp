#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    // -1 + 3 - 5 + 7 - 9 ...
    // f(1) = -1
    // f(2) = 2
    // f(3) = -3
    // f(4) = 4


    if(n % 2 == 1) cout << "Kosuke\n";
    else cout << "Sakurako\n";

    
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
