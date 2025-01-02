#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}



void solve(){
    ll n; cin >> n;
    ll k[n];
    for(int i = 0; i < n; i++) cin >> k[i];

    // k1, ..., kn

    // a1, ..., an

    // S = a1 + ... + an

    // need k1a1 , k2a2, ..., knan > S

    // k1a1 > S <-> a1 > S/k1 <-> a1 + ... an > S/k1 + ... S/kn <-> S > S(1/k1 + ... 1/kn)
    // <-> 1 > (1/k1 + ... 1/kn)

    // S > S(ksum/nlcm)

    // conj: works iff sum(1/ki) <  1

    // find lcm amongst all ki

    ll nlcm = k[0];

    for(int i = 1; i < n; i++){
        nlcm = lcm(nlcm, k[i]);
    }

    ll ksum = 0;
    ll ans[n];
    for(int i = 0; i < n; i++){
        ans[i] = nlcm/k[i];
        ksum += ans[i];
    }

    //cout << ksum  << ' ' << nlcm << '\n';

    if(ksum >= nlcm){
        cout << -1 << '\n';
        return;
    }

    for(ll e : ans) cout << e << ' ';
    cout << '\n';















}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
