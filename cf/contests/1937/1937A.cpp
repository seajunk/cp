#include <iostream>
#define ll long long
using namespace std;

ll log(ll n){
    ll ans = 1;
    while(ans <= n){
        ans *= 2;
    }

    return ans / 2;
}

void solve(){
    ll n; cin >> n;
    cout << log(n) << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
