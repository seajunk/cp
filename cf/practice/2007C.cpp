#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void solve(){
    ll n, a, b; cin >> n >> a >> b;
    ll g = gcd(a, b);

    ll c[n];
    for(int i = 0; i < n; i++) cin >> c[i];


    for(int i = 0; i < n; i++) c[i] %= g;
    sort(c, c + n);

    set<ll> seen;
    vector<ll> d;

    for(int i = 0; i < n; i++){
        if(seen.find(c[i]) == seen.end()){ d.push_back(c[i]); seen.insert(c[i]);}
    }

    ll ans = c[n - 1] - c[0];
    for(int i = 0; i < d.size() - 1; i++){
        ans = min(d[i] + g - d[i + 1], ans);
    }

    cout << ans << '\n';




    












    
    


    // 2 3
    // 7 14
    // 1 0
    // 1 2

    // 5 10
    // 1 0
    // 2 1

    // 5 15
    // 1 1
    // 2 0


    // gcd(2, 3) = 1

    // 2 3
    // 1 3 4 6












}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

