#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, q; cin >> n >> q;
    ll x[n];

    // 1 3 4 6 10 13 15


    // points in (x_1, x_2) are covered by 1*(n - 1) segments(?)
    // points in (x_i, x_i+1) are covered by i(n - i) segments(?)
    // point x_2 is covered by 5 segments
    // point x_i is covered by (i - 1)(n - i + 1) + (n - i)
    // point x_2 is covered by (2 - 1)(7 - 2 + 1) + (7 - 2) = 6 + 5 = 11 segments

    for(int i = 0; i < n; i++) cin >> x[i];

    map<ll, ll> cnt;

    for(int i = 0; i < n; i++){
        ll I = i + 1;
        if(cnt.find((I - 1)*(n - I + 1) + n - I) == cnt.end()) cnt[(I - 1)*(n - I + 1) + n - I] = 1;
        else cnt[(I - 1)*(n - I + 1) + n - I]++;
    }


    for(int i = 0; i < n - 1; i++){
        ll I = i + 1;
        ll temp = I * (n - I);
        if(cnt.find(temp) == cnt.end()) cnt[temp] = 0;
        cnt[temp] += x[i + 1] - x[i] - 1;
    }




    for(int i = 0; i < q; i++){
        ll k; cin >> k;
        cout << cnt[k] << '\n';
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
