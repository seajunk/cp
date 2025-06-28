#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    ll pfs[n + 1];
    pfs[0] = 0;
    for(int i = 1; i <= n; i++) pfs[i] = pfs[i - 1] + a[i - 1];
    
    ll mn = a[0];
    ll mx = a[n - 1];


    // ans = minimal achievable diff 

    // binary search?

    // ans \in [0, mx - mn]
    ll lo = 0, hi = mx - mn + 1; 

    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;


        // check if error of mid is attainable?

        // for r = 0 to n - 1, l = 0
        // if subarray a[l, r] cant be handled by a single carver, carver++ and continue with l = r
        // a[l, r] is handleable by single carver if exists some x st d(a[l], x) <= mid and d(a[r], x) <= mid
        // 

        ll carver = 1;
        ll l = 0;

        for(int r = 0; r < n; r++){
            ll x = (a[l] + a[r])/2;
            if(abs(a[l] - x) <= mid && abs(a[r] - x) <= mid) continue; // carver can handle a[l, r]
            else{
                carver += 1;
                l = r;
            }
        }

        if(carver <= 3) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
