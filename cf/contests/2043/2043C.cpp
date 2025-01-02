#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    ll unique = LLONG_MAX;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] != 1 && a[i] != -1) unique = a[i];
    }

    ll pfs[n + 1];
    pfs[0] = 0;
    for(int i = 1; i <= n; i++) pfs[i] = pfs[i - 1] + a[i - 1]; 








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
