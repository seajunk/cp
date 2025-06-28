#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll q; cin >> q;

    ll pfsum[n + 1];
    pfsum[0] = 0;
    for(int i = 1; i <= n; i++) pfsum[i] = a[i - 1] + pfsum[i - 1];

    for(int i = 0; i < q; i++){
        ll l, u; cin >> l >> u;
        l--;
        // running ith segments results in gain of u - i + 1 gains
        /*
           runnign i segments total results in gain of 


           u + (u - 1) + (u - 2) + ... + (u - (i - 1))
           = u*i - (sum from 1 to i -1)
           = u*i - (i*(i-1))/2;

           ternary search?

           difference array?

           get first index in difference array which is < 0 ?

           if no such index exists, check the end points ?
        */


        // find first guy where difference array is <= 0
        // maximize over [l + 1, n - 1]

        ll lo = l, hi = n - 1;
        while(lo < hi){
            ll mid = (hi - lo + 1)/2 + lo;
            ll first = pfsum[mid] - pfsum[l];
            ll second = pfsum[mid + 1] - pfsum[l];
            //cout << (u*first - (first*(first - 1)/2)) << ' ' << (u*second - (second*(second - 1)/2)) << '\n';
            if((u*second - (second*(second - 1)/2)) - (u*first - (first*(first - 1)/2)) > 0) lo = mid;
            else hi = mid - 1;
        }
        if(lo == l){
            // no guy in difference array was increasing

            cout << (l + 1) << '\n';



        }
        else{
            cout << (lo + 1) << '\n';
        }
    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
