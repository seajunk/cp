#include <iostream>
#include <set>
#define ll long long
using namespace std;



ll mod(ll n, ll k){
    return ((n % k) + k) % k;
}

ll gcd(ll a, ll b){
    if(a == 0) return abs(b);
    else return gcd(b % a, a);
}

void solve(){
    ll n; cin >> n;
    ll a[n], b[n];
    ll mx = -1 * 10e9;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    } 
    if(n == 1){
        cout << 1 << '\n';
        return;
    }

    for(int i = 0; i < n; i++) b[i] = mx - a[i];  
    ll ngcd = b[0];
    for(int i = 0; i < n; i++){
        ngcd = gcd(ngcd, b[i]);
    }

    ll ans = 0;
    set<ll> s;
    for(int i = 0; i < n; i++){
        ans += (mx - a[i]) / ngcd;
        s.insert((mx - a[i]) / ngcd);
    }

    ll mn = 1;
    while(s.find(mn) != s.end()) mn++;

    ans += min(mn, n);
    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
