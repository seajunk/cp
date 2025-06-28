#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll p[n];
    for(int i = 0; i < n; i++) cin >> p[i];

    // if chip on i, can move to any j in [0, i) st p[i] > p[j] 


    ll pfmn[n + 1];
    pfmn[0] = LLONG_MAX;
    for(int i = 1; i <= n; i++) pfmn[i] = min(pfmn[i - 1], p[i - 1]);
    ll mn = LLONG_MAX;
    ll cnt = 0;

    for(int i = 0; i < n; i++){
        if(pfmn[i] > p[i]) continue;
        if(mn < p[i]) continue;
        else{
            mn = p[i];
            cnt++;
        }
    }

    cout << cnt << '\n';








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
