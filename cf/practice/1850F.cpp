#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i]; 

    // trap at t catches frog a[i] if t is multiple of a[i]
    // so frog with hop 2 is caught by 2, 4, 6, 8, ...
    // frog with hop k is caught by k, 2k, 3k, ...

    vector<ll> cnt(n + 1, 0);

    for(int i = 0; i < n; i++){
        if(a[i] > n) continue;
        cnt[a[i]]++;
    }

    // n + n/2 + n/3 + ... = nlogn 
    vector<ll> toadd(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= n/i; j++){
            toadd[i*j] += cnt[i];
        }
    }
    
    for(int i = 1; i <= n; i++){
        cnt[i] += toadd[i];
    }

    ll mx = LLONG_MIN;
    for(int i = 1; i <= n; i++){
        mx = max(mx, cnt[i]);
    }

    cout << mx << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

