#include <iostream>
#include <map>
#define ll int32_t
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> M;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll temp = ~a[i] & ((1ll << 31) - 1);

        if(M.find(temp) != M.end() && M[temp] > 0) M[temp]--;
        else{
            if(M.find(a[i]) == M.end()) M[a[i]] = 1;
            else M[a[i]]++;
            ans++;
        }


    }
    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
