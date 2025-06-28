#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;


    if(a1 == 0){
        if(a2 || a3 || a4){
            cout << 1 << '\n';
            return;
        }
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;

    ans += a1;

    ans += 2*min(a2, a3);

    ans += min(a1, a4 + max(a2, a3) - min(a2, a3)); 
    if(a1 < a4 + max(a2, a3) - min(a2, a3)) ans += 1; 

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
