#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    ll l, r; cin >> l >> r;

    if(l % 2 == 0) l++;
    if(r % 2 != 0) r++;

    cout << (r - l + 1) / 4 << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
