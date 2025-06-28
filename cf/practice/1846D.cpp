#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
    ll n; cin >> n;
    ld d, h; cin >> d >> h;
    ld y[n];
    for(int i = 0; i < n; i++) cin >> y[i];

    ld ans = 0;

    for(int i = 0; i < n; i++){
        ld area = h*d/2;

        if(i != 0 && (y[i - 1] + h > y[i])){
            // remove from area the intersection between current triangle and previous triangle 

            // want to know the length of the base of the intersecting triangle 


            ld slope = (d/2) / h;

            ld base = d - 2 * slope * (y[i] - y[i - 1]);
            ld height = h - (y[i] - y[i - 1]);

            area -= 0.5 * (base * height);
        }
        ans += area;
    }
    cout << setprecision(10) << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
