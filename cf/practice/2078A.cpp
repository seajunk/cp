#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, x; cin >> n >> x;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        sum += in;
    }

    if(sum % n != 0){
        cout << "NO\n";
        return;
    }

    if(sum / n != x){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
