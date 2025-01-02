#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2)), b(n, vector<ll>(2));

    for(int i = 0; i < n; i++){
        cin >> a[i][1];
        a[i][0] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i][1];
        b[i][0] = i;
    }


    sort(a.begin(), a.end(), [](vector<ll> l, vector<ll> r){ return l[1] < r[1];});

    vector<ll> inverted(n);


    unordered_map<ll, ll> idx;
    for(int i = 0; i < n; i++){
        inverted[i] = b[a[i][0]][1];
        idx[inverted[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        cout << i << ' ';
    }
    cout << '\n';

    for(ll inv : inverted) cout << inv << ' ';
    cout << '\n';





    









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
