#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    ll a[n];
    for(int i = 0; i < m; i++) cin >> a[i];

    ll q[k];
    for(int i = 0; i < k; i++) cin >> q[i];


    if(k < n - 1){
        for(int i = 0; i < m; i++){
            cout << 0;
        }
        cout << '\n';
    }
    else if(k == n - 1){
        ll curr = 0;
        for(int i = 1; i <= n; i++) curr ^= i;
        for(int i = 0; i < k; i++) curr ^= q[i];

        for(int i = 0; i < m; i++){
            if(a[i] == curr) cout << '1'; 
            else cout << '0';
        }
        cout << '\n';
    }
    else{
        for(int i = 0; i < m; i++) cout << '1';
        cout << '\n';
    }
}


int main(){
    ll t; cin >> t;
    while(t--) solve();
}
