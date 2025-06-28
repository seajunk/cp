#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    // 1 4 1 

    // 1 1 1
    // 1 4 1
    // 1 1 1

    // need leftmost and rightmost elements a[l], a[r] st a[l], a[r] >= a[i]
    // then max size of rect containing every cell of a[i] is r - l + 1

    // loop through a, for each first instance of color a[i], binary search and find rightmost element whose color is ge to a[i], ans[i] = i - bs - 1 times 2


    ll sfmx[n + 1];
    sfmx[n] = LLONG_MIN;
    for(int i = n - 1; i >= 0; i--) sfmx[i] = max(sfmx[i + 1], a[i]);

    ll pfmx[n + 1];
    pfmx[0] = LLONG_MIN;
    for(int i = 1; i <= n; i++) pfmx[i] = max(pfmx[i - 1], a[i - 1]);


    vector<ll> ans(k, 0);
    vector<bool> seen(k, false);

    for(int i = 0; i < n; i++){
        if(seen[a[i] - 1]) continue;


        ll lo, hi;
        // right most guy bigger than a[i]
        // t t t t f f 

        lo = 0, hi = n;
        while(lo < hi){
            ll mid = (hi - lo)/2 + lo;

            if(a[i] <= sfmx[mid]) lo = mid + 1;
            else hi = mid;
        }

        ll r = lo - 1;

        lo = 0, hi = n;
        // left most guy bigger than a[i]
        // f f t t t t t t
        while(lo < hi){
            ll mid = (hi - lo)/2 + lo;

            if(a[i] <= pfmx[mid + 1]) hi = mid;
            else lo = mid + 1;
        }

        ll l = lo;


        seen[a[i] - 1] = true;
        ans[a[i] - 1] = 2 * (r - l + 1);
    }

    for(int i = 0; i < k; i++) cout << ans[i] << ' ';
    cout << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
