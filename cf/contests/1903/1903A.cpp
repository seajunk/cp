#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(k >= 2){
        cout << "YES\n";
        return;
    }
    
    bool nondec = true;

    for(int i = 1; i < n; i++){
        if(a[i - 1] > a[i]) nondec = false;
    }

    if(nondec){
        cout << "YES\n";
    }
    else cout << "NO\n";

    
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
