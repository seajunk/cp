#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll mx = 0;
    for(int i = 0; i < n; i++) mx = max(mx, a[i]); 

    for(int i = 0; i < m; i++){
        char op;
        ll l, r;
        cin >> op >> l >> r;
        if(op == '+'){
            if(l <= mx && mx <= r) mx++;
        }
        else{
            if(l <= mx && mx <= r) mx--;
        }

        cout << mx << '\n';


        


    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
