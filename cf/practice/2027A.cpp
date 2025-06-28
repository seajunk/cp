#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll h[n], w[n];
    ll mxh = 0, mxw = 0;
    for(int i = 0; i < n; i++){
        cin >> w[i];
        cin >> h[i];
        mxh = max(mxh, h[i]);
        mxw = max(mxw, w[i]);
    }

    cout << 2*(mxh + mxw) << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
