#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, q; cin >> n >> q;
    ll c[n];
    for(int i = 0; i < n; i++) cin >> c[i];


    ll ones[n + 1]; // # of ones in [i, n)
    ones[0] = 0;
    for(int i = 1; i <= n; i++) ones[i] = ones[i - 1] + (c[i - 1] == 1);



    ll pfs[n + 1]; // sum over [i, n) with c[i] - 1
    pfs[0] = 0;
    for(int i = 1; i <= n; i++) pfs[i] = pfs[i - 1] + c[i - 1] - 1;




    for(int i = 0; i < q; i++){
        ll l, r; cin >> l >> r;

        if(l == r){
            cout << "NO\n";
            continue;
        }


        l--;


        if(ones[r] - ones[l] > pfs[r] - pfs[l]) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
