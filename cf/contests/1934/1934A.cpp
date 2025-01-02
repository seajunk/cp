#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long 
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll mx = abs(a[0] - a[n - 1]) + abs(a[n - 1] - a[1]) + abs(a[1] - a[n - 2]) + abs(a[n - 2] - a[0]);
    cout << mx << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
