#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

    // conj: each swe will work at most a[i] / b[i] hours 

    // heur: the earlier swes have more advantage in choosing how much they work
    // ie earlier swe will work less than they can

    ll n, k; cin >> n >> k; // no of swe, hours needed for project
    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll m[n];
    for(int i = 0; i < n; i++) m[i] = a[i]/b[i];

    ll sfs[n + 1]; // sfs[i] = sum(m) [i, n)
    sfs[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        sfs[i] = sfs[i + 1] + m[i];
    }


    ll c[n];

    for(int i = 0; i < n; i++){
        ll sf = sfs[i + 1]; // [i + 1, n)
        ll needed = max(k - sf, 0ll);

        if(needed > m[i]){
            c[i] = 0;
        }
        else{
            c[i] = needed;
            k -= needed;
        }
    }

    for(ll e : c) cout << e << ' ';
    cout << '\n';









}

int main(){
    solve();
}
