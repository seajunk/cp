#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x, m; cin >> x >> m;

    // want # of y, 1 <= y <= m st x != y, x^y divides x or y 

    // x > 0, y > 0

    // obs: x^y < x, y
    // d | n -> d <= n/2
    // d <= n/2 -> d and n have different msb positions

    // if y >= 2*x = x<<1 then y^x has same msb as y -> y^x can not be a divisor of y or x
    // check just y < 2*x


    ll ans = 0;
    for(int y = 1; y < min(m + 1, 2*x); y++){
        if(y == x) continue;
        if((x%(x^y)) == 0 | (y%(x^y)) == 0) ans++;
    }

    cout << ans << '\n';










}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

