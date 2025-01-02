#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    ll idx;

    for(int i = 0; i < n; i++){
        bool p1win = true;

        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(abs(a[i] - a[j]) % k == 0){
                p1win = false;
            }
        }
        if(p1win){
            cout << "YES\n";
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << "NO\n";


    
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
