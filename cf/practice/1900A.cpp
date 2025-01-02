#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    char row[n];
    for(int i = 0; i < n; i++) cin >> row[i];
    
    vector<ll> len;

    ll curr = 0;
    for(int i = 0; i <= n; i++){
        if(row[i] == '.' && i < n) curr++;
        else{
            if(curr > 0) len.push_back(curr);
            curr = 0;
        }
    }

    ll ans = 0;
    for(ll l : len){
        if(l < 3) ans += l;
        else{
            cout << 2 << '\n';
            return;
        }
    }
    cout << ans << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
