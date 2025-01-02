#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> closest(n, -1);

    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]){
            closest[i] = i - 1;
        }
        else{
            closest[i] = closest[i - 1];
        }
    }

    ll q; cin >> q;
    for(int i = 0; i < q; i++){
        ll l, r; cin >> l >> r; l--; r--;

        if(closest[r] >= l){
            cout << closest[r] + 1 << ' ' << r + 1 << '\n';
        }
        else{
            cout << -1 << ' ' << -1 << '\n';
        }

    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

