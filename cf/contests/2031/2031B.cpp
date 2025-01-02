#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll p[n];
    for(int i = 0; i < n; i++) cin >> p[i];

    for(int i = 1; i < n; i++){
        if(p[i - 1] == p[i] + 1){
            ll temp = p[i - 1];
            p[i - 1] = p[i];
            p[i] = temp;
        }
    }

    bool valid = true;

    for(int i = 0; i < n; i++){
        if(p[i] != i + 1){
            valid = false;
        }
    }

    if(valid) cout << "YES\n";
    else cout << "NO\n";


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
