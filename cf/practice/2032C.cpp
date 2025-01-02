#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve2(){
    ll n; cin >> n;
    ll a[n];
    
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);



    ll ans = LLONG_MAX;

    // for each i = [0, n - 3], optimal is largest j st i < j, a[i] + a[i + 1] > a[j]


    ll l = 0, r = l + 1;
    while(l + 1 <= r && r < n && l < n){
        if(a[l] + a[l + 1] > a[r]){
            ans = min(ans, l + n - 1 - r);
            r++;
        }
        else l++;
    }

    cout << ans << '\n';



}


void solve(){
    ll n; cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());




    // find biggest subarray b of a st b[0] + b[1] > b[-1]

    ll lo = 2, hi = n + 1; // [t, t, ..., f, f, f] 

    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;

        bool valid = false;
        for(int i = 0; i < n - mid + 1; i++){
            if(a[i] + a[i + 1] > a[i + mid - 1]) valid = true;
        }

        if(valid) lo = mid + 1;
        else hi = mid;
    }

    cout << n - (lo - 1) << '\n';


    


}

int main(){
    ll t; cin >> t;
    while(t--) solve2();
}
