#include <iostream>
#include <cmath>
#include <vector>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
    ll n, c, pos, neg;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    c = 0, neg = 0, pos = 0;
    ll old_neg = neg;
    ll old_pos = pos;
    for(int i = 0; i <= n; i++){
        old_neg = neg;
        old_pos = pos;
        neg = old_neg + a[i];
        pos = max(old_pos + a[i], abs(old_neg + a[i]));
    }

    cout << old_pos << '\n';

}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}
