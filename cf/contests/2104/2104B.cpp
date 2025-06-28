#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll pfsum[n + 1];
    pfsum[0] = 0;
    for(int i = 1; i <= n; i++) pfsum[i] = pfsum[i - 1] + a[i - 1];

    ll pfmx[n + 1];
    pfmx[0] = LLONG_MIN;
    for(int i = 1; i <= n; i++) pfmx[i] = max(pfmx[i - 1] , a[i - 1]);


    for(int k = 1; k <= n; k++){
        /*
           want suffix sum of last k elements, but if theres a guy left of last k elements greater than the left most guy, swap them
        */


        ll sum = pfsum[n] - pfsum[n - k];

        if(a[n - k] <  pfmx[n - k]) sum += pfmx[n - k] - a[n - k];

        cout << sum << ' ';
    }
    cout << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
