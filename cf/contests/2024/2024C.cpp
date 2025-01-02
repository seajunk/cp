#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    // (a[i][0], a[i][1]), (a[i + 1][0], a[i + 1][1])
    // (a, b), (c, d)
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2));
    for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1]; 


    //sort(a.begin(), a.end(), [](auto l, auto r){});

    for(int i = 0; i < n; i++){
        cout << a[i][0] << ' ' << a[i][1] << ' ';
    }
    cout << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
