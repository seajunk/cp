#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[2][n];
    for(int i = 0; i < n; i++) cin >> a[0][i];
    for(int i = 0; i < n; i++) cin >> a[1][i];


    // note in every column except the connecting column, optimal choice is to use the larger of the two values in the column. if top is larger put column left of connecting, if bottom is larger put column right of connecting

    // conj: connecting column is the one with the largest smaller value

    ll idx = 0;
    ll mxmn = LLONG_MIN;
    for(int i = 0; i < n; i++){
        ll mn = min(a[0][i], a[1][i]);
        if(mn >= mxmn){
            idx = i;
            mxmn = mn;
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(i == idx){
            ans += a[0][i];
            ans += a[1][i];
        }
        else{
            ans += max(a[0][i], a[1][i]);
        }
    }

    cout << ans << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
