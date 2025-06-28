#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];


    ll ors = 0;

    for(int i = 0; i < m; i++) ors |= b[i];


    ll mx = 0;
    ll mn = 0;

    if(n % 2 == 0){
        for(int i = 0; i < n; i++) mx ^= a[i];
        for(int i = 0; i < n; i++) a[i] |= ors; 
        for(int i = 0; i < n; i++) mn ^= a[i];
    }
    else{
        for(int i = 0; i < n; i++) mn ^= a[i];
        for(int i = 0; i < n; i++) a[i] |= ors; 
        for(int i = 0; i < n; i++) mx ^= a[i];
    }

    cout << mn << ' ' << mx << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
